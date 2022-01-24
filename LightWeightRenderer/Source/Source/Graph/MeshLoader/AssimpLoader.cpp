//
// Created by MisThe on 2022/1/24.
//

#include "../../../Head/Graph/MeshLoader/AssimpLoader.h"

BaseLoader::TempMesh *AssimpLoader::starLoad(std::string path) {
    this->loadMesh(path);
    return this->tempMesh;
}


void AssimpLoader::loadMesh(std::string path) {
    Assimp::Importer importer;
    const aiScene* scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_GenSmoothNormals | aiProcess_FlipUVs | aiProcess_CalcTangentSpace);
    if(!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
        LogUtil::LogError("AssimpLoadModel","load model failed");
    tempMesh = new TempMesh();
    processNode(scene->mRootNode, scene);
}

void AssimpLoader::processNode(aiNode *node, const aiScene *scene) {
    for(unsigned int i = 0; i < node->mNumMeshes; i++)
    {
        aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
        processMesh(mesh);
    }
    for(unsigned int i = 0; i < node->mNumChildren; i++)
    {
        processNode(node->mChildren[i], scene);
    }
}

void AssimpLoader::processMesh(aiMesh *mesh) {
    for (int i = 0; i < mesh->mNumVertices; ++i) {
        //读取顶点坐标
        tempVertex.position = glm::vec3(mesh->mVertices[i].x, mesh->mVertices[i].y, mesh->mVertices[i].z);
        //读取法线信息
        tempVertex.normal = glm::vec3(mesh->mNormals[i].x, mesh->mNormals[i].y, mesh->mNormals[i].z);
        //读取切线信息
        tempVertex.tangent = glm::vec3(mesh->mTangents[i].x, mesh->mTangents[i].y, mesh->mTangents[i].z);
        //读取颜色信息以及读取纹理坐标
        if (mesh->mColors[0])
            tempVertex.color = glm::vec4(mesh->mColors[0][i].r, mesh->mColors[0][i].g, mesh->mColors[0][i].b,mesh->mColors[0][i].a);
        if (mesh->mTextureCoords[0])
            tempVertex.texCoord = glm::vec2(mesh->mTextureCoords[0][i].x, mesh->mTextureCoords[0][i].y);
        int tempIndex = 0;
        for (int j = 1; j < 8; ++j) {
            if (mesh->mColors[j])
                tempIndex = tempVertex.addStandby(glm::vec4(mesh->mColors[j][i].r, mesh->mColors[j][i].g, mesh->mColors[j][i].b,mesh->mColors[j][i].a),tempIndex);
            if (mesh->mTextureCoords[j])
                tempIndex = tempVertex.addStandby(glm::vec4(mesh->mTextureCoords[j][i].x, mesh->mTextureCoords[j][i].y,0.0f,0.0f),tempIndex);
        }
        tempMesh->addVertex(tempVertex);
    }
    for (int i = 0; i < mesh->mNumFaces; ++i) {
        aiFace face = mesh->mFaces[i];
        for (int j = 0; j < face.mNumIndices; ++j) {
            tempMesh->addIndex(face.mIndices[j]);
        }
    }
}
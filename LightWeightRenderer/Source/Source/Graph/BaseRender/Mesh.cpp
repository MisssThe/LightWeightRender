//
// Created by MisThe on 2022/1/21.
//

#include "../../../Head/Graph/BaseRender/Mesh.h"

Mesh::Mesh(std::string path) {
    this->meshName = path;
    this->loadMesh(path);
}

void Mesh::loadMesh(std::string path) {
    //从路径加载网格
    BaseLoader::MeshInfo* meshInfo = GeneralLoader::Load(path);
    this->processMesh(meshInfo);
}

void Mesh::processMesh(BaseLoader::MeshInfo* meshInfo) {
    if (meshInfo != nullptr) {
        unsigned int VBO, EBO;
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        glGenBuffers(1, &EBO);
        glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, meshInfo->vertexSize, meshInfo->vertex, GL_STATIC_DRAW);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, meshInfo->indexSize, meshInfo->index, GL_STATIC_DRAW);
        int length = meshInfo->attriVec.size();
        for (int i = 0; i < length; ++i) {
            glVertexAttribPointer(i, meshInfo->attriVec[i].vertexNum, GL_FLOAT, GL_FALSE, meshInfo->attriVec[i].offset * sizeof(float), (void*)meshInfo->attriVec[i].initOffset);
            glEnableVertexAttribArray(i);
        }
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
    }
}

void Mesh::use() {
    glBindVertexArray(this->VAO);
}

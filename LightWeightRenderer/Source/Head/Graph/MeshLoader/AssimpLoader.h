//
// Created by MisThe on 2022/1/24.
//

#ifndef LIGHTWEIGHTRENDERER_ASSIMPLOADER_H
#define LIGHTWEIGHTRENDERER_ASSIMPLOADER_H


#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include "../../../../Utils/Head/LogUtil.h"
#include "BaseLoader.h"

class AssimpLoader : public BaseLoader
{
public:
    TempMesh *starLoad(std::string path) override;
private:
    void loadMesh(std::string path);
    void processNode(aiNode *node, const aiScene *scene);
    void processMesh(aiMesh* mesh);
};


#endif //LIGHTWEIGHTRENDERER_ASSIMPLOADER_H

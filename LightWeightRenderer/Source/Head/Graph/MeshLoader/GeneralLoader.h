//
// Created by MisThe on 2022/1/24.
//

#ifndef LIGHTWEIGHTRENDERER_GENERALLOADER_H
#define LIGHTWEIGHTRENDERER_GENERALLOADER_H

#include "AssimpLoader.h"

class GeneralLoader {
public:
    enum MeshType
    {
        ANY,FBX,OBJ
    };
public:
    static BaseLoader::MeshInfo* Load(std::string path,MeshType type = MeshType::ANY) {
        BaseLoader*baseLoader = nullptr;
        switch (type) {
            case MeshType::ANY:
                baseLoader = new AssimpLoader;
                break;
            case MeshType::FBX:
                break;
            case MeshType::OBJ:
                break;
        }
        return baseLoader->load(path);
    }
};


#endif //LIGHTWEIGHTRENDERER_GENERALLOADER_H

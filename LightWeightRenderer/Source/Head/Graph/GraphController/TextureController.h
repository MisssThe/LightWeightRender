//
// Created by MisThe on 2022/2/8.
//

#ifndef LIGHTWEIGHTRENDERER_TEXTURECONTROLLER_H
#define LIGHTWEIGHTRENDERER_TEXTURECONTROLLER_H


#include "../BaseRender/Texture.h"

class TextureController {
public:
    static void Init();
    static Texture*GetTexture(std::string name);
private:
    static bool isReady;
    static std::string texture_config_path;
    static std::unordered_map<std::string,Texture*> texture_map;
    static std::unordered_map<std::string,std::string> texture_path_map;
};


#endif //LIGHTWEIGHTRENDERER_TEXTURECONTROLLER_H

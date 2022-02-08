//
// Created by MisThe on 2022/1/26.
//

#ifndef LIGHTWEIGHTRENDERER_TEXTURE_H
#define LIGHTWEIGHTRENDERER_TEXTURE_H

#include <string>
#include <glad/glad.h>
#include "../../../../Utils/Head/LogUtil.h"
#include "../../../../Utils/Head/FileUtil.h"

class Texture {
public:
    Texture(std::string path);
    ~Texture();
    int getWidth();
    int getHeight();
    void use();
private:
    int width,height;
    unsigned int texture;
};

#endif //LIGHTWEIGHTRENDERER_TEXTURE_H

//
// Created by MisThe on 2022/1/26.
//

#ifndef LIGHTWEIGHTRENDERER_TEXTURE_H
#define LIGHTWEIGHTRENDERER_TEXTURE_H

#include <string>

class Texture {
public:
    Texture();
    Texture(std::string path);
    ~Texture();
    int getWidth();
    int getHeight();
    int getID();
private:
    int width,height;
    int textureID;
};

#endif //LIGHTWEIGHTRENDERER_TEXTURE_H

//
// Created by MisThe on 2022/1/26.
//

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "../../../Head/Graph/BaseRender/Texture.h"

Texture::~Texture() {

}

Texture::Texture(std::string path) {
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    int nrChannels;
    unsigned char *data = stbi_load(path.c_str(), &width, &height, &nrChannels, 0);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        LogUtil::LogError("load texture","Failed to load texture");
    }
    stbi_image_free(data);
}

int Texture::getWidth() {
    return this->width;
}

int Texture::getHeight() {
    return this->height;
}

void Texture::use() {
    glBindTexture(GL_TEXTURE_2D, texture);
}

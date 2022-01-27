//
// Created by MisThe on 2022/1/26.
//

#include "../../../Head/Graph/BaseRender/Texture.h"

Texture::Texture() {

}

Texture::~Texture() {

}

Texture::Texture(std::string path) {

}

int Texture::getWidth() {
    return this->width;
}

int Texture::getHeight() {
    return this->height;
}

int Texture::getID() {
    return this->textureID;
}

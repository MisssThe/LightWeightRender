//
// Created by MisThe on 2022/1/21.
//

#ifndef LIGHTWEIGHTRENDERER_TRANSFORM_H
#define LIGHTWEIGHTRENDERER_TRANSFORM_H


#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Transform {
public:
    glm::mat4 getMatrix();
    void setPosition(float x,float y,float z);
    void setRotation(float x,float y,float z);
    void setScale(float x,float y,float z);
    glm::vec3 getPosition();
    glm::vec3 getRotation();
    glm::vec3 getScale();
private:
    glm::mat4 matrix;
    glm::vec3 position;
    glm::vec3 rotation;
    glm::vec3 scale;
private:
    void createMatrix();
};


#endif //LIGHTWEIGHTRENDERER_TRANSFORM_H

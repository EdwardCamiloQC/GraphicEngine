#include <camera.h>
#include <math.h>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>

const float step = 0.01f;

Camera::Camera(float posX, float posY, float posZ){
    positionCam.x = posX;
    positionCam.y = posY;
    positionCam.z = posZ;
    view = glm::mat4(1.0f);
    view = glm::translate(view, glm::vec3(posX, posY, posZ));
}

void Camera::translate(enum CameraMovement movement){
    switch(movement){
        case LEFT:
            view = glm::translate(view, glm::vec3(step, 0.0f, 0.0f));
            positionCam.x += 0.1f;
            break;
        case RIGHT:
            view = glm::translate(view, glm::vec3(-step, 0.0f, 0.0f));
            positionCam.x -= 0.1f;
            break;
        case UP:
            view = glm::translate(view, glm::vec3(0.0f, -step, 0.0f));
            positionCam.y += 0.1f;
            break;
        case DOWN:
            view = glm::translate(view, glm::vec3(0.0f, step, 0.0f));
            positionCam.y -= 0.1f;
            break;
        case FORWARD:
            view = glm::translate(view, glm::vec3(0.0f, 0.0f, step));
            positionCam.z -= 0.1f;
            break;
        case BACKWARD:
            view = glm::translate(view, glm::vec3(0.0f, 0.0f, -step));
            positionCam.z += 0.1f;
            break;
    }
    //glUniformMatrix4fv(glGetUniformLocation(idShader, "view"), 1, GL_FALSE, &view[0][0]);
}

void Camera::rotate(float offsetX, float offsetY){
    float theta1, theta2;
    try{
        if(offsetX == 0 && offsetY == 0)
            throw 0.0f;
        if(offsetX == 0)
            throw 90.0f;
        theta1 = atan(abs(offsetY) / abs(offsetX));
    }catch(float angle){
        theta1 = angle;
    }
    theta2 = 90.0f - theta1;
    if(offsetY < 0)
        theta2 = theta2 * (-1.0f);
    if(offsetX > 0)
        theta1 = theta1 * (-1.0f);
    std::cout << theta1 << "---" << theta2<< std::endl;
    //view = glm::rotate(view, glm::radians(theta1), glm::vec3(1.0f, 0.0f, 0.0f));
    view = glm::rotate(view, glm::radians(15.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            
}

glm::mat4 Camera::getViewMatrix(){
    return view;
}

Camera::~Camera(){
    //
}
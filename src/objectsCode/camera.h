#ifndef _CAMERA_H_
    #define _CAMERA_H_

    #include <glm/glm.hpp>

    enum CameraMovement{
        LEFT, RIGHT,
        UP, DOWN,
        FORWARD, BACKWARD
    };

    enum CameraRotate{
        PITCH,
        YAW
    };

    struct position{
        float x, y, z;
    };

    class Camera{
        public:
            Camera(float posX, float posY, float posZ);
            void translate(enum CameraMovement movement);
            void rotate(float offsetX, float offsetY);
            glm::mat4 getViewMatrix();
            ~Camera();
        private:
            struct position positionCam;
            glm::mat4 view;
    
    };
#endif

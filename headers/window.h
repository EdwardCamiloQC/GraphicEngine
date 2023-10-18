#ifndef _PRINCIPALWINDOW_H_
    #define _PRINCIPALWINDOW_H_

    #include <GLFW/glfw3.h>
    #include <stdint.h>

    class Principal{
        public:
            Principal(uint16_t width, uint16_t height, const char* nameWindow);
            int isItRunning();
            void processEvents();
            void cambiar();
            void render();
            bool getLeft();
            void setLeft(bool);
            bool getRight();
            void setRight(bool);
            bool getUp();
            void setUp(bool);
            bool getDown();
            void setDown(bool);
            bool getHor();
            void setHor(bool);
            bool getAntHor();
            void setAntHor(bool);
            ~Principal();
        private:
            bool flagLeft, flagRight, flagUp, flagDown, flagRotateHor, flagRotateAntHor;
            GLFWwindow* window;
            float backgroundColor[4];
    };

    void framebuffer_size_callback(GLFWwindow* window, int width, int height);
    void mouse_callback(GLFWwindow* window, double xPosIn, double yPosIn);
    void scroll_callback(GLFWwindow* window, double xOffset, double yOffset);
    void processInput(GLFWwindow* window);
#endif
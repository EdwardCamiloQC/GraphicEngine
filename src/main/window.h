#ifndef _PRINCIPALWINDOW_H_
    #define _PRINCIPALWINDOW_H_

    #include <GLFW/glfw3.h>
    #include <stdint.h>
    #include <scene.h>

    class WindowEngine{
        public:
            WindowEngine(uint16_t width, uint16_t height);
            void run();
            ~WindowEngine();
        public:
            uint32_t ancho;
            uint32_t alto;
            const char* NAME_WINDOW = "Engine";
        private:
            Scene scene;
            GLFWwindow* window;
            float backgroundColor[4];
            unsigned int idP;
    };

    void framebuffer_size_callback(GLFWwindow* window, int width, int height);
    void mouse_callback(GLFWwindow* window, double xPosIn, double yPosIn);
    void scroll_callback(GLFWwindow* window, double xOffset, double yOffset);
    void processInput(GLFWwindow* window);
#endif
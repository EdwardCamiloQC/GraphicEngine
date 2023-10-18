#include <glad/glad.h>
#include <window.h>
#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height){
    glViewport(0, 0, width, height);
}

void mouse_callback(GLFWwindow* window, double xPosIn, double yPosIn){
    float xPos = static_cast<float>(xPosIn);
    float yPos = static_cast<float>(yPosIn);
}

void scroll_callback(GLFWwindow* window, double xOffset, double yOffset){
}

void processInput(GLFWwindow* window, bool* left, bool* right, bool* up, bool* down){
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
        glfwSetWindowShouldClose(window, true);
    }
    if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS){
        *left = true;
    }
    if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS){
        *right = true;
    }
    if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS){
        *up = true;
    }
    if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS){
        *down = true;
    }
}

Principal::Principal(uint16_t width, uint16_t height, const char* nameWindow):flagLeft(false), flagRight(false), flagUp(false), flagDown(false), flagRotateHor(false), flagRotateAntHor(false), window(nullptr){
    backgroundColor[0] = 0.1f;
    backgroundColor[1] = 0.1f;
    backgroundColor[2] = 0.1f;
    backgroundColor[3] = 0.1f;
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    window = glfwCreateWindow(width, height, nameWindow, NULL, NULL);
    if(window == NULL){
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);

    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        std::cout << "Failed to initializze GLAD" << std::endl;
    }
    glEnable(GL_DEPTH_TEST);
}

int Principal::isItRunning(){
    return !glfwWindowShouldClose(window);
}

void Principal::processEvents(){
    processInput(window, &flagLeft, &flagRight, &flagUp, &flagDown);
}

void Principal::cambiar(){
    glfwSwapBuffers(window);
    glfwPollEvents();
}

void Principal::render(){
    glClearColor(backgroundColor[0], backgroundColor[1], backgroundColor[2], backgroundColor[3]);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

bool Principal::getLeft(){
    return flagLeft;
}

void Principal::setLeft(bool left){
    flagLeft = left;
}

bool Principal::getRight(){
    return flagRight;
}

void Principal::setRight(bool right){
    flagRight = right;
}

bool Principal::getUp(){
    return flagUp;
}

void Principal::setUp(bool flag){
    flagUp = flag;
}

bool Principal::getDown(){
    return flagDown;
}

void Principal::setDown(bool flag){
    flagDown = flag;
}

bool Principal::getHor(){
    return flagRotateHor;
}

void Principal::setHor(bool flag){
    flagRotateHor = flag;
}

bool Principal::getAntHor(){
    return flagRotateAntHor;
}

void Principal::setAntHor(bool flag){
    flagRotateAntHor = flag;
}

Principal::~Principal(){
    glfwTerminate();
}
#include <glad/glad.h>
#include <window.h>
#include <glm/glm.hpp>
#include <iostream>
#include <shaders.h>
#include <mapFactory.h>

#ifdef VIEW_2D_ENABLE
    #define VISION true
#else
    #define VISION false
#endif

bool flagMouse = true;
float lastX = 600 / 2.0f;
float lastY = 800 / 2.0f;
float fov = 45.0f;
float deltaTime = 0.0f;
float lastFrame = 0.0f;

void framebuffer_size_callback(GLFWwindow* window, int width, int height){
    glViewport(0, 0, width, height);
}

void mouse_callback(GLFWwindow* window, double xPosIn, double yPosIn){
    float xPos = static_cast<float>(xPosIn);
    float yPos = static_cast<float>(yPosIn);
    if(flagMouse){
        lastX = xPos;
        lastY = yPos;
        flagMouse = false;
    }
    float xoffset = xPos - lastX;
    float yoffset = lastY - yPos;
    lastX = xPos;
    lastY = yPos;
    //camera.ProcessMouseMovement(xoffset, yoffset, false);
}

void scroll_callback(GLFWwindow* window, double xOffset, double yOffset){
    fov -= (float)yOffset;
    if (fov < 1.0f)
        fov = 1.0f;
    if (fov > 45.0f)
        fov = 45.0f;
}

void processInput(GLFWwindow* window, Camera& camera){
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
        glfwSetWindowShouldClose(window, true);
    }
    if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS){
        camera.ProcessKeyboard(LEFT, deltaTime);
    }
    if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS){
        camera.ProcessKeyboard(RIGHT, deltaTime);
    }
    if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS){
        camera.ProcessKeyboard(FORWARD, deltaTime);
    }
    if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS){
        camera.ProcessKeyboard(BACKWARD, deltaTime);
    }
}

WindowEngine::WindowEngine(uint16_t width, uint16_t height):ancho(width), alto(height), scene(), window(nullptr){
    backgroundColor[0] = 0.1f;
    backgroundColor[1] = 0.1f;
    backgroundColor[2] = 0.1f;
    backgroundColor[3] = 0.1f;
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    window = glfwCreateWindow(width, height, NAME_WINDOW, NULL, NULL);
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
    if(VISION){
        glDisable(GL_DEPTH_TEST);
    }else{
        glEnable(GL_DEPTH_TEST);
    }
    ProgramShaders program("./src/shaders/nivel1.vs", "./src/shaders/nivel1.fs");
    idP = program.shaderProgramId;

    MapFactory factory;
    scene.loadMap(factory.createMap(PYRAMID, 0.0f, 0.0f, 0.0f));
}

void WindowEngine::run(){
    while(!glfwWindowShouldClose(window)){
        float currentFrame = static_cast<float>(glfwGetTime());
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
        processInput(window, scene.requestCamera());
        glClearColor(backgroundColor[0], backgroundColor[1], backgroundColor[2], backgroundColor[3]);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glUseProgram(idP);
        
        scene.drawMap(idP);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

WindowEngine::~WindowEngine(){
    scene.eraseMap();
    glDeleteProgram(idP);
    glfwTerminate();
}
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

bool point1 = true, point2 = false;
float lastX = 600 / 2.0f;
float lastY = 800 / 2.0f;
float fov = 45.0f;
float deltaTime = 0.0f;
float lastFrame = 0.0f;

void framebuffer_size_callback(GLFWwindow* window, int width, int height){
    glViewport(0, 0, width, height);
}

void mouseInput(GLFWwindow* window, Camera& camera){
    double posX, posY;
    float x, y, offsetX, offsetY;
    int stateLeft = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT);
    if(stateLeft == GLFW_PRESS){
        glfwGetCursorPos(window, &posX, &posY);
        x = static_cast<float>(posX);
        y = static_cast<float>(posY);
        offsetX = x - lastX;
        offsetY = y - lastY;
        lastX = x;
        lastY = y;
        camera.rotate(offsetX, offsetY);
    }
    if(stateLeft == GLFW_RELEASE){
        lastX = 800 / 2;
        lastY = 600 / 2;
    }
}

void processInput(GLFWwindow* window, Camera& camera){
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
        glfwSetWindowShouldClose(window, true);
    }
    if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS){
        camera.translate(LEFT);
    }
    if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS){
        camera.translate(RIGHT);
    }
    if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS){
        camera.translate(UP);
    }
    if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS){
        camera.translate(DOWN);
    }
    if(glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS){
        camera.translate(FORWARD);
    }
    if(glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS){
        camera.translate(BACKWARD);
    }
}

WindowEngine::WindowEngine(uint16_t width, uint16_t height):ancho(width), alto(height), scene(), window(nullptr){
    backgroundColor[0] = 0.3f;
    backgroundColor[1] = 0.3f;
    backgroundColor[2] = 0.3f;
    backgroundColor[3] = 1.0f;
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
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);

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
    scene.loadMap(factory.createMap(CORAZON, 0.0f, 0.0f, -3.0f));
}

WindowEngine::WindowEngine(const WindowEngine& w):scene(), window(nullptr){
    ancho = w.ancho;
    alto = w.alto;
    for(size_t i = 0; i < 4; i++){
        backgroundColor[i] = w.backgroundColor[i];
    }
    if(w.window){
        window = w.window;
    }
}

WindowEngine::~WindowEngine(){
    scene.eraseMap();
    glDeleteProgram(idP);
    glfwTerminate();
}

void WindowEngine::run(){
    while(!glfwWindowShouldClose(window)){
        float currentFrame = static_cast<float>(glfwGetTime());
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
        processInput(window, scene.requestCamera());
        mouseInput(window, scene.requestCamera());
        glClearColor(backgroundColor[0], backgroundColor[1], backgroundColor[2], backgroundColor[3]);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glUseProgram(idP);
        
        scene.drawMap(idP);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

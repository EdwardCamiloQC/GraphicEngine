#include <glad/glad.h>
#include <engine.h>
#include <shaders.h>
#include <map1.h>

Engine::Engine():m_window(nullptr){
    m_window = std::make_unique<Principal>(ancho, alto, nombre);
    ProgramShaders program("./shaders/nivel1.vs", "./shaders/nivel1.fs");
    idP = program.getIdProgram();
    Map1::initMap1(VAO, VBO, EBO);
}

void Engine::run(){
    while(m_window->isItRunning()){
        m_window->processEvents();
        m_window->render();
        glUseProgram(idP);
        Map1::implementMap1(VAO);
        m_window->cambiar();
    }
}

Engine::~Engine(){
    Map1::deleteMap1(VAO, VBO, EBO);
    glDeleteProgram(idP);
}
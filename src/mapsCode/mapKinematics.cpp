#include <mapKinematics.h>
#include <glad/glad.h>
#include <glm/gtc/matrix_transform.hpp>

MapKinematics::MapKinematics(float xCam, float yCam, float zCam):Map(xCam, yCam, zCam){
    dataVertex1.reserve(1);
    indicesVertex1.reserve(1);
    normalsVertex1.reserve(1);
    mapaPrub.loadFromFile("../../ProyectosGraficos/resources/Prisma/Prisma.obj", dataVertex1, indicesVertex1, normalsVertex1);
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, dataVertex1.size() * sizeof(float), &dataVertex1[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicesVertex1.size() * sizeof(int), &indicesVertex1[0], GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindVertexArray(0);
}

void MapKinematics::implementMap(unsigned int idShader){
    glm::mat4 model = glm::mat4(1.0f);
    glm::mat4 view = camera.getViewMatrix();
    glm::mat4 projection = glm::mat4(1.0f);
    
    projection = glm::perspective(glm::radians(45.0f), (float)800 / (float)600, 0.1f, 100.0f);
    glUniformMatrix4fv(glGetUniformLocation(idShader, "model"), 1, GL_FALSE, &model[0][0]);
    glUniformMatrix4fv(glGetUniformLocation(idShader, "view"), 1, GL_FALSE, &view[0][0]);
    glUniformMatrix4fv(glGetUniformLocation(idShader, "projection"), 1, GL_FALSE, &projection[0][0]);
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, indicesVertex1.size(), GL_UNSIGNED_INT, &indicesVertex1[0]);
    glBindVertexArray(0);
}

MapKinematics::~MapKinematics(){
    glDeleteBuffers(1, &VBO);
    glDeleteVertexArrays(1, &VAO);
}

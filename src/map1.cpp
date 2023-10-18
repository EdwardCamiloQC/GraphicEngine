#include <map1.h>
#include <figure.h>
#include <glad/glad.h>

namespace Map1{
    void initMap1(unsigned int &vao, unsigned int &vbo, unsigned int &ebo){
        glGenVertexArrays(1, &vao);
        glGenBuffers(1, &vbo);
        glGenBuffers(1, &ebo);

        glBindVertexArray(vao);

        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferData(GL_ARRAY_BUFFER, sizeof(Figure::generateSquare().vertex), Figure::generateSquare().vertex, GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(Figure::generateSquare().indices), Figure::generateSquare().indices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
        glEnableVertexAttribArray(1);

        glBindVertexArray(0);
    }

    void implementMap1(unsigned int vao){
        glBindVertexArray(vao);
        glDrawElements(GL_TRIANGLES, sizeof(Figure::generateSquare().indices)/sizeof(float), GL_UNSIGNED_INT, 0);
    }

    void deleteMap1(unsigned int &vao, unsigned int &vbo, unsigned int &ebo){
        glDeleteVertexArrays(1, &vao);
        glDeleteBuffers(1, &vbo);
        glDeleteBuffers(1, &ebo);
    }
}

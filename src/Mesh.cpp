#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Mesh.h"

Mesh::Mesh(float* vertices, size_t size)
{
    // Vertex Array Object and Vertex Buffer Object
    vao = 0;
    vbo = 0;

    // Creates GPU objects
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);

    // Bind VAO
    glBindVertexArray(vao);

    // Uploads vertex data into VBO
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);

    // Stores attribute layout in currently bound VAO
    glVertexAttribPointer(
        0, 3, GL_FLOAT, GL_FALSE,
        3 * sizeof(float),
        (void*)0
    );

    glEnableVertexAttribArray(0);

    // Unbind for safety
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

Mesh::~Mesh()
{
    glDeleteBuffers(1, &vbo);
    glDeleteVertexArrays(1, &vao);
}

unsigned int Mesh::GetVAO() const {
    return this->vao;
}

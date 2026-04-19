#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Mesh.h"

// Updated Mesh Constructor
Mesh::Mesh(float* vertices, size_t vSize, unsigned int* indices, size_t iSize)
{
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glGenBuffers(1, &ebo); // Create EBO

    glBindVertexArray(vao);

    // VBO Setup
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, vSize, vertices, GL_STATIC_DRAW);

    // EBO Setup - This must happen while VAO is bound
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, iSize, indices, GL_STATIC_DRAW);

    // Attribute Pointers
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Note: Do NOT unbind the EBO before unbinding the VAO. 
    // The VAO stores the EBO binding.
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

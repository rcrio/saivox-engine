#include <glad/glad.h>

#include "buffers/VAO.h"

VAO::VAO() {
    glGenVertexArrays(1, &id);
}

VAO::~VAO() {
    glDeleteVertexArrays(1, &id);
}

void VAO::Bind() const {
    glBindVertexArray(id);
}

void VAO::Unbind() const {
    glBindVertexArray(0);
}

void VAO::LinkAttrib(unsigned int layout)
{   // Index, size (2d or 3d), type, normalized, stride, pointer
    glVertexAttribPointer(layout, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(layout);
}
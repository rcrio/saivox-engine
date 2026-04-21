#include <glad/glad.h>

#include "VAO.h"

/**
 * @brief Generates a OpenGL VAO and assigns the id to our VAO.
 */
VAO::VAO() {
    glGenVertexArrays(1, &id);
}

/**
 * @brief Destructor that deletes the OpenGL VAO.
 */
VAO::~VAO() {
    glDeleteVertexArrays(1, &id);
}

/**
 * @brief Binds the VAO.
 */
void VAO::Bind() const {
    glBindVertexArray(id);
}

/**
 * @brief Unbinds the VAO.
 */
void VAO::Unbind() const {
    glBindVertexArray(0);
}

/**
 * @brief Sets vertex attribute pointers.
 */
void VAO::LinkAttrib(unsigned int layout)
{   // Index, size (2d or 3d), type, normalized, stride, pointer
    glVertexAttribPointer(layout, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(layout);
}
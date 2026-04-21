#include "VBO.h"

VBO::VBO(const void* vertices, unsigned int size_of_vertices)
{
    glGenBuffers(1, &id);
    glBindBuffer(GL_ARRAY_BUFFER, id);
    glBufferData(GL_ARRAY_BUFFER, size_of_vertices, vertices, GL_STATIC_DRAW);
}


VBO::~VBO()
{
    glDeleteBuffers(1, &id);
}

/**
 * @brief Binds the VBO.
 */
void VBO::Bind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, id);
}

/**
 * @brief Unbinds the VBO.
 */
void VBO::Unbind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

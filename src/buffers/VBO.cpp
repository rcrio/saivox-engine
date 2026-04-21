#include "buffers/VBO.h"

// Vertices could be struct or float array
VBO::VBO()
{
    glGenBuffers(1, &id);
    // glBindBuffer(GL_ARRAY_BUFFER, id);
    // glBufferData(GL_ARRAY_BUFFER, size_of_vertices, vertices, GL_STATIC_DRAW);
}

VBO::~VBO()
{
    glDeleteBuffers(1, &id);
}

void VBO::Bind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, id);
}

void VBO::Unbind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VBO::SetDataAndBind(const void* vertices, unsigned int size_of_vertices)
{
    glBindBuffer(GL_ARRAY_BUFFER, id);
    glBufferData(GL_ARRAY_BUFFER, size_of_vertices, vertices, GL_STATIC_DRAW);
}
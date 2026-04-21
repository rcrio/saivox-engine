#include "buffers/EBO.h"

EBO::EBO()
{
    glGenBuffers(1, &id);
    // glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
    // glBufferData(GL_ELEMENT_ARRAY_BUFFER, size_of_vertices, indices, GL_STATIC_DRAW);
}

EBO::~EBO()
{
    glDeleteBuffers(1, &id);
}

void EBO::Bind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, id);
}

void EBO::Unbind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void EBO::SetDataAndBind(const void* indices, unsigned int size_of_indices)
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size_of_indices, indices, GL_STATIC_DRAW);
}
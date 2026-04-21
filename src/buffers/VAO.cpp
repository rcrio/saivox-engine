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

void VAO::LinkAttribute(
    unsigned int layout,
    int componentCount,
    unsigned int type,
    bool normalized,
    size_t stride,
    const void* offset
)
{   
    glVertexAttribPointer(
        layout,
        componentCount,
        type,
        normalized,
        stride,
        offset
    );

    glEnableVertexAttribArray(layout);
}
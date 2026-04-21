#pragma once

#include <glad/glad.h>

class VBO {
public:
    VBO(const void* data, unsigned int size);
    ~VBO();

    void Bind() const;
    void Unbind() const;
private:
    unsigned int id;
};
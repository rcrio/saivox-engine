#ifndef SAIVOX_ENGINE_MESH_H
#define SAIVOX_ENGINE_MESH_H

#include <memory>

#include "buffers/VAO.h"
#include "buffers/VBO.h"
#include "buffers/EBO.h"

class Mesh {
public:
    Mesh(float* vertices, size_t size, unsigned int* indices, size_t iSize);
    ~Mesh();

    const VAO& GetVAO() const;
    const VBO& GetVBO() const;
    const EBO& GetEBO() const;

private:
    // Mesh generates the ids from their constructors
    VAO vao;
    VBO vbo;
    EBO ebo;
};

#endif
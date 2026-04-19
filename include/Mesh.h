#ifndef SAIVOX_ENGINE_MESH_H
#define SAIVOX_ENGINE_MESH_H

class Mesh {
public:
    Mesh(float* vertices, size_t size);
    ~Mesh();

    unsigned int GetVAO() const;

private:
    unsigned int vao;
    unsigned int vbo;
};

#endif
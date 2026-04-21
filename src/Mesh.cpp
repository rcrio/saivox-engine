#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Mesh.h"

Mesh::Mesh(float* vertices, size_t vSize, unsigned int* indices, size_t iSize)
{
    // This can be refactored to be clearer, but should be fine.
    vao.Bind();
    vbo.SetDataAndBind(vertices, vSize);
    ebo.SetDataAndBind(indices, iSize);
    vao.LinkAttrib(0);
    vao.Unbind();
    // vbo.Unbind();
    // ebo.Unbind();
}

Mesh::~Mesh()
{

}

const VAO& Mesh::GetVAO() const
{
    return vao;
}

const VBO& Mesh::GetVBO() const
{
    return vbo;
}

const EBO& Mesh::GetEBO() const
{
    return ebo;
}


/*
VAO& GetVAO() const;
    VBO& GetVBO() const;
    EBO& GetEBO() const;
*/


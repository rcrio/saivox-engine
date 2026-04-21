#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Mesh.h"

Mesh::Mesh(float* vertices, size_t vSize, unsigned int* indices, size_t iSize)
{
    vao.Bind();

    // Could refactor and split this
    vbo.SetDataAndBind(vertices, vSize);
    ebo.SetDataAndBind(indices, iSize);

    // Could refactor by not hardcoding everything
    vao.LinkAttribute(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    vao.LinkAttribute(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    vao.LinkAttribute(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));

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


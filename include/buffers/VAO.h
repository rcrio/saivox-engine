#pragma once

/**
 * @brief Configures vertex attributes.
 * 
 * This VAO structure is mostly used for abstraction and organisation of code.
 * In reality and most tutorials, you can do this by
 * raw OpenGL calls.
 * 
 * * Example usage:
 * @code
 * vao.Bind();
 * vbo.Bind();
 * vao.LinkAttrib(0, 3, GL_FLOAT, false, sizeof(Vertex), (void*)0);
 * vbo.Unbind(); # Optional safety, can refactor and remove to reduce calls
 * vao.Unbind(); # Optional safety, can refactor and remove to reduce calls
 * @endcode
 */

class VAO {
public:
    VAO();
    ~VAO();

    void Bind() const;
    void Unbind() const;

    void LinkAttrib(unsigned int layout);

private:
    unsigned int id;
};
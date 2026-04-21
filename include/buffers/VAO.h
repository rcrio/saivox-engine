#pragma once

class VAO {
public:
    /// @brief Creates a Vertex Array Object (VAO).
    VAO();

    /// @brief Deletes the VAO.
    ~VAO();

    /// @brief Binds this VAO as the current vertex array object.
    void Bind() const;

    /// @brief Unbinds the current vertex array object.
    void Unbind() const;

    /// @brief Links a vertex attribute layout to this VAO.
    /// @param layout The attribute layout location in the shader (e.g., 0 for position).
    void LinkAttrib(unsigned int layout);

private:
    /// @brief OpenGL vertex array object ID.
    unsigned int id;
};
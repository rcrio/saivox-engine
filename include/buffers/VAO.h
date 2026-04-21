#pragma once

class VAO {
public:
    /// @brief Creates a Vertex Array Object (VAO) and populates this object's ID.
    VAO();

    /// @brief Deletes the VAO.
    ~VAO();

    /// @brief Binds this VAO as the current vertex array object.
    void Bind() const;

    /// @brief Unbinds the current vertex array object.
    void Unbind() const;

    /// @brief Links a vertex attribute layout to this VAO.
    /// @param layout The attribute layout location in the shader (e.g., 0 for position).
    void LinkAttribute(
    unsigned int layout,
    int componentCount,
    unsigned int type,
    bool normalized,
    size_t stride,
    const void* offset
    );

private:
    /// @brief OpenGL vertex array object ID.
    unsigned int id;
};
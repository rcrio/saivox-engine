#pragma once

class VBO {
public:
    /// @brief Creates a Vertex Buffer Object (VBO) and uploads vertex data to the GPU.
    /// Also populates this object's ID.  
    VBO();

    /// @brief Deletes the VBO.
    ~VBO();

    /// @brief Binds this VBO as the current GL_ARRAY_BUFFER.
    void Bind() const;

    /// @brief Unbinds the current GL_ARRAY_BUFFER.
    void Unbind() const;

    /// @param vertices Pointer to the vertex data (e.g., float array or struct array).
    /// @param size_of_vertices Size of the vertex data in bytes.
    void SetDataAndBind(const void* vertices, unsigned int size_of_vertices);

private:
    /// @brief OpenGL buffer object ID.
    unsigned int id;
};
#pragma once

#include <glad/glad.h>

class EBO {
public:
    /// @brief Creates an Element Buffer Object (EBO) and uploads index data to the GPU.
    
    EBO();
    
    /// @brief Deletes the EBO.
    ~EBO();

    /// @brief Binds the EBO.
    void Bind() const;

    /// @brief Unbinds the EBO.
    void Unbind() const;

    /// @param indices Pointer to the index data (e.g., unsigned int array).
    /// @param size_of_indices Size of the index data in bytes.
    void SetDataAndBind(const void* indices, unsigned int size_of_indices);

private:
    /// @brief OpenGL buffer object ID.
    unsigned int id;
};
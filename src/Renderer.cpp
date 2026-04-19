#include <glad/glad.h> // Needs to be in this order.
#include <GLFW/glfw3.h>

#include "Renderer.h"
#include <iostream>
#include <string>

Renderer::Renderer() {
    // GLSL (Graphics Library Shading Language) shader source setup.
    vertexShaderSource = "#version 330 core\n"
        "layout (location = 0) in vec3 aPos;\n"
        "void main() { gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0); }\0";

    fragmentShaderSource = "#version 330 core\n"
        "out vec4 FragColor;\n"
        "uniform vec4 uColor;\n" // Added uniform
        "void main() { FragColor = uColor; }\0";
}

unsigned int Renderer::CompileShader(unsigned int shaderType, const char* shaderSource) {
    unsigned int shader = glCreateShader(shaderType);
    glShaderSource(shader, 1, &shaderSource, NULL);
    glCompileShader(shader);
    return shader;
}

void Renderer::CheckShader(unsigned int shader, const std::string& name) {
    int success;
    char infoLog[512];

    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        throw std::runtime_error(
            std::string(name + " shader failed!\n") + infoLog
        );
    }
}

unsigned int Renderer::CompileProgram(unsigned int vertexShader, unsigned int fragmentShader) {
    unsigned int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    return shaderProgram;
}

void Renderer::CheckProgram(unsigned int shaderProgram) {
    int success;
    char infoLog[512];

    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, 0, infoLog);
        throw std::runtime_error(
            std::string("Shader program linking failed!\n") + infoLog
        );
    }
}

void Renderer::SetupShaders() {
    unsigned int vertexShader = CompileShader(GL_VERTEX_SHADER, vertexShaderSource);
    CheckShader(vertexShader, "Vertex Shader");

    unsigned int fragmentShader = CompileShader(GL_FRAGMENT_SHADER, fragmentShaderSource);
    CheckShader(fragmentShader, "Fragment Shader");
    
    unsigned int shaderProgram = CompileProgram(vertexShader, fragmentShader);
    CheckProgram(shaderProgram);

    uColorLocation = glGetUniformLocation(shaderProgram, "uColor");

    // Cleanup for memory
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

void Renderer::CreateMesh(unsigned int& vao, unsigned int& vbo, float* vertices, size_t size) {
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);

    glBindVertexArray(vao);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void Renderer::Draw(unsigned int vao, float r, float g, float b) {
    // Tell OpenGL which shader process to use
    glUseProgram(shaderProgram);

    // Set colour uniform
    glUniform4f(uColorLocation, r, g, b, 1.0f);

    // Bind the geometry and draw
    glBindVertexArray(vao);
    glDrawArrays(GL_TRIANGLES, 0, 3); // Draws 3 vertices

    // Clean up state (optional but good practice)
    glBindVertexArray(0);
}
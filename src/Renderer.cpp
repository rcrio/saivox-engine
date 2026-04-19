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
    vertexShader = CompileShader(GL_VERTEX_SHADER, vertexShaderSource);
    CheckShader(vertexShader, "Vertex Shader");

    fragmentShader = CompileShader(GL_FRAGMENT_SHADER, fragmentShaderSource);
    CheckShader(fragmentShader, "Fragment Shader");
    
    shaderProgram = CompileProgram(vertexShader, fragmentShader);
    CheckProgram(shaderProgram);

    uColorLocation = glGetUniformLocation(shaderProgram, "uColor");

    // Cleanup for memory
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

void Renderer::Draw(const Mesh& mesh, float r, float g, float b)
{
    // Use shader
    glUseProgram(shaderProgram);
    
    // Set uniform
    glUniform4f(uColorLocation, r, g, b, 1.0f);

    // Use mesh (VAO is inside it now)
    glUseProgram(shaderProgram);
    glBindVertexArray(mesh.GetVAO());
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glBindVertexArray(0);
}
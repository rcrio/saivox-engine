#include <glad/glad.h> // Needs to be in this order.
#include <GLFW/glfw3.h>
#include <iostream>

#include "Shader.h"

Shader::Shader() {
    // Needs refactoring later on
    this->vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos, 1.0);\n"
    "}\0";

    this->fragmentShaderSource = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "uniform vec4 ourColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = ourColor;\n"
    "}\n\0";
}

Shader::Shader(const char* vertexShaderSource, const char* fragmentShaderSource) {
    this->vertexShaderSource = vertexShaderSource;
    this->fragmentShaderSource = fragmentShaderSource;
}

void Shader::SetUpShaders() {
    vertexShader = CompileShader(GL_VERTEX_SHADER, vertexShaderSource);
    CheckShader(vertexShader, "Vertex");

    fragmentShader = CompileShader(GL_FRAGMENT_SHADER, fragmentShaderSource);
    
    shaderProgram = CompileProgram(vertexShader, fragmentShader);

    // Cleanup for memory
    DeleteShaders();
}

unsigned int Shader::CompileShader(unsigned int shaderType, const char* shaderSource) {
    unsigned int shader = glCreateShader(shaderType);
    glShaderSource(shader, 1, &shaderSource, NULL);
    glCompileShader(shader);

    if (!CheckShader(shader, "Vertex")) return 0;
    
    return shader;
}

bool Shader::CheckShader(unsigned int shader, const std::string& shaderName) {
    std::cout << "Check if " << shaderName  << " shader compilation worked... ";

    int success;
    char infoLog[512];

    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        std::cout << "Failed! \n" << infoLog << "\n";
        return false;
    }
    else {
        std::cout << "Success!\n";
        return true;
    }
}

unsigned int Shader::CompileProgram(unsigned int vertexShader, unsigned int fragmentShader) {
    unsigned int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    if (!CheckProgram(shaderProgram)) return 0;

    return shaderProgram;
}

bool Shader::CheckProgram(unsigned int shaderProgram) {
    std::cout << "Checking if linking program worked... ";
    int success;
    char infoLog[512];

    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, 0, infoLog);
        std::cout << "Failed! \n" << infoLog << "\n";
        return false;
    }
    else {
        std::cout << "Success!\n";
        return true;
    }
}

void Shader::DeleteShaders() {
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

const unsigned int Shader::GetShaderProgram() const{
    return shaderProgram;
}
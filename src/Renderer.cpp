#include <glad/glad.h> // Needs to be in this order.
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include <glm/glm.hpp> 
#include <glm/gtc/type_ptr.hpp> 

#include "Renderer.h"
#include "Camera.h"


Renderer::Renderer() {
    // GLSL (Graphics Library Shading Language) shader source setup.
    vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";

    fragmentShaderSource = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "\n"
    "void main()\n"
    "{\n"
    "    FragColor = vec4(1.0, 0.5, 0.2, 1.0);\n"
    "}\n";
    
    
    /*
    "#version 330 core\n"
        "out vec4 FragColor;\n"
        "uniform vec4 uColor;\n" // Added uniform
        "void main() { FragColor = uColor; }\0";
        */
}

unsigned int Renderer::CompileShader(unsigned int shaderType, const char* shaderSource) {
    unsigned int shader = glCreateShader(shaderType);
    glShaderSource(shader, 1, &shaderSource, NULL);
    glCompileShader(shader);
    return shader;
}

void Renderer::CheckShader(unsigned int shader, const std::string& shaderName) {
    std::cout << "Check if " << shaderName  << " shader compilation worked... ";

    int success;
    char infoLog[512];

    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        std::cout << "Failed! \n" << infoLog << "\n";
    }
    else {
        std::cout << "Success!\n";
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
    std::cout << "Checking if linking program worked... ";
    int success;
    char infoLog[512];

    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, 0, infoLog);
        std::cout << "Failed! \n" << infoLog << "\n";
    }
    else {
        std::cout << "Success!\n";
    }
}

void Renderer::SetupShaders() {
    vertexShader = CompileShader(GL_VERTEX_SHADER, vertexShaderSource);
    CheckShader(vertexShader, "Vertex");

    fragmentShader = CompileShader(GL_FRAGMENT_SHADER, fragmentShaderSource);
    CheckShader(fragmentShader, "Fragment");
    
    shaderProgram = CompileProgram(vertexShader, fragmentShader);
    CheckProgram(shaderProgram);

    // Cleanup for memory
    DeleteShaders();
}

void Renderer::DeleteShaders() {
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

void Renderer::Draw(const Mesh& mesh, float r, float g, float b) {
    glUseProgram(shaderProgram);
    /*
    glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
    glDrawArrays(GL_TRIANGLES, 0, 3);
    */
}

void Renderer::BeginFrame(const Camera& camera, float aspectRatio) {
    // COPY camera state ONCE per frame
    view = camera.GetViewMatrix();
    projection = camera.GetProjectionMatrix(aspectRatio);
}
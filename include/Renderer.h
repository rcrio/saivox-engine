#ifndef SAIVOX_ENGINE_RENDERER_H
#define SAIVOX_ENGINE_RENDERER_H

#include <string>

class Renderer {
public:
    Renderer();

    unsigned int CompileShader(unsigned int shaderType, const char* shaderSource);
    void CheckShader(unsigned int shader, const std::string& name);

    unsigned int CompileProgram(unsigned int vertexShader, unsigned int fragmentShader);
    void CheckProgram(unsigned int shaderProgram);

    void SetupShaders();
    void CreateMesh(unsigned int& vao, unsigned int& vbo, float* vertices, size_t size);
    void Draw(unsigned int vao, float r, float g, float b);

private:
    const char* vertexShaderSource;
    const char* fragmentShaderSource;
    unsigned int vertexShader;
    unsigned int fragmentShader;
    unsigned int shaderProgram;
    unsigned int uColorLocation;
};

#endif
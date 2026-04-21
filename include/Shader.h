#pragma once

#include <string>

class Shader {
public:
    Shader();
    
    Shader(const char* vertexShaderSource, const char* fragmentShaderSource);

    const unsigned int GetShaderProgram() const;

    void SetUpShaders();

private:
    unsigned int CompileShader(unsigned int shaderType, const char* shaderSource);
    bool CheckShader(unsigned int shader, const std::string& shaderName);
    unsigned int CompileProgram(unsigned int vertexShader, unsigned int fragmentShader);
    bool CheckProgram(unsigned int shaderProgram);
    void DeleteShaders();

    const char* vertexShaderSource;
    const char* fragmentShaderSource;
    unsigned int vertexShader;
    unsigned int fragmentShader;
    unsigned int shaderProgram;
};
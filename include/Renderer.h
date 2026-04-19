#ifndef SAIVOX_ENGINE_RENDERER_H
#define SAIVOX_ENGINE_RENDERER_H

#include <string>
#include <glm/glm.hpp> 
#include <glm/gtc/type_ptr.hpp> 

#include "Mesh.h"

class Renderer {
public:
    Renderer();

    unsigned int CompileShader(unsigned int shaderType, const char* shaderSource);
    void CheckShader(unsigned int shader, const std::string& name);

    unsigned int CompileProgram(unsigned int vertexShader, unsigned int fragmentShader);
    void CheckProgram(unsigned int shaderProgram);

    void SetupShaders();

    void Draw(const Mesh& mesh,
                    const glm::mat4& view,
                    const glm::mat4& projection,
                    float r, float g, float b);

    void SetViewProjection(const glm::mat4& view, const glm::mat4& projection);

private:
    const char* vertexShaderSource;
    const char* fragmentShaderSource;
    unsigned int vertexShader;
    unsigned int fragmentShader;
    unsigned int shaderProgram;
    unsigned int uColorLocation;
    int modelLoc;
    int viewLoc;
    int projectionLoc;
};

#endif
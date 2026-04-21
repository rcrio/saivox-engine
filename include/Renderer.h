#ifndef SAIVOX_ENGINE_RENDERER_H
#define SAIVOX_ENGINE_RENDERER_H

#include <string>
#include <glm/glm.hpp> 
#include <glm/gtc/type_ptr.hpp> 

#include "Mesh.h"

class Renderer {
public:
    Renderer();

    void Draw(const unsigned int shaderProgram, const Mesh& mesh);

private:
    const char* vertexShaderSource;
    const char* fragmentShaderSource;
    unsigned int vertexShader;
    unsigned int fragmentShader;
    unsigned int shaderProgram;
    unsigned int uColorLocation;
};

#endif
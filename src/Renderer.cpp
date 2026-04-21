#include <glad/glad.h> // Needs to be in this order.
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include <glm/glm.hpp> 
#include <glm/gtc/type_ptr.hpp> 

#include "Renderer.h"


Renderer::Renderer() {

}

void Renderer::Draw(const unsigned int shaderProgram, const Mesh& mesh) {
    glUseProgram(shaderProgram);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    mesh.GetVAO().Bind();
    // glDrawArrays(GL_TRIANGLES, 0, 6);

    double timeValue = glfwGetTime();
    float greenValue = static_cast<float>(sin(timeValue) / 2.0 + 0.5);
    int vertexColorLocation = glGetUniformLocation(shaderProgram, "ourColor");
    glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    // glBindVertexArray(0); // no need to unbind it every time
}
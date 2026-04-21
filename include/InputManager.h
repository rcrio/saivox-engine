#pragma once

#include <glad/glad.h> // GLAD needs to be before GLFW
#include <GLFW/glfw3.h>

#include "InputState.h"

class InputManager {
public:
    InputManager();
    void processInput(GLFWwindow* window);
    const InputState& GetInput() const;

private:
    InputState current;
    InputState previous;

    double lastX = 0.0;
    double lastY = 0.0;
    bool firstMouse = true;
};
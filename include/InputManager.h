#pragma once

#include "InputState.h"
#include <GLFW/glfw3.h>

class InputManager {
public:
    InputManager();
    void Update(GLFWwindow* window);

    const InputState& GetInput() const;

private:
    InputState current;
    InputState previous;
};
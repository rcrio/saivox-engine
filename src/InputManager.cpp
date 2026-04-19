#include "InputManager.h"

InputManager::InputManager() {

}

void InputManager::Update(GLFWwindow* window)
{
    previous = current;

    current.W = glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS;
    current.A = glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS;
    current.S = glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS;
    current.D = glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS;

    current.Esc = glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS;
    current.Enter = glfwGetKey(window, GLFW_KEY_ENTER) == GLFW_PRESS;

    current.EscPressedThisFrame =
        current.Esc && !previous.Esc;

    current.EnterPressedThisFrame =
        current.Enter && !previous.Enter;
}

const InputState& InputManager::GetInput() const
{
    return current;
}
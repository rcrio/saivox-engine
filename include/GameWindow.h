#ifndef SAIVOX_ENGINE_GAMEWINDOW_H
#define SAIVOX_ENGINE_GAMEWINDOW_H

#include <GLFW/glfw3.h>

class GameWindow {
public:
    void Run();

private:
    GLFWwindow* window;
    bool Initialize();
    void Cleanup();
    void PrintVersion();
};

#endif
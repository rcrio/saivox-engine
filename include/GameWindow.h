#ifndef SAIVOX_ENGINE_GAMEWINDOW_H
#define SAIVOX_ENGINE_GAMEWINDOW_H

#include "InputManager.h"
#include "Game.h"

class GameWindow {
public:
    GameWindow();
    ~GameWindow();

    void Run();

    // Prevents copying
    GameWindow(const GameWindow&) = delete;
    GameWindow& operator=(const GameWindow&) = delete;

private:
    void Initialize();
    // Static needed to pass into glfwSetFramebufferSizeCallBack
    static void FrameBufferSizeCallback(GLFWwindow* window, int width, int height);
    void Cleanup();
    void PrintVersion();

    GLFWwindow* window;
    InputManager inputManager;
    Game game;
    
};

#endif
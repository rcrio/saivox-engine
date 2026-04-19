#ifndef SAIVOX_ENGINE_GAMEWINDOW_H
#define SAIVOX_ENGINE_GAMEWINDOW_H

#include <GLFW/glfw3.h>
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
    void Cleanup();
    void PrintVersion();

    GLFWwindow* window;
    // Game game;
    InputManager inputManager;
    
};

#endif
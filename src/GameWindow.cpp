#include <glad/glad.h> // GLAD needs to be before GLFW
#include <GLFW/glfw3.h>
#include <iostream>

#include "GameWindow.h"
#include "Game.h"
#include "InputState.h"


GameWindow::GameWindow() {
    Initialize();
}

GameWindow::~GameWindow() {
    Cleanup();
}

/**
 * @brief Initializes GLFW dependencies, prepares needed variables for
 * the main game loop, and then runs the main game loop.
 */
void GameWindow::Run() {
    Game game;
    
    float lastFrame = 0.0f;

    // -- MAIN GAME LOOP --
    while (!glfwWindowShouldClose(window) && game.IsRunning()) {
        float currentFrame = glfwGetTime();
        float deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        glfwPollEvents(); 
        
        // REFACTOR NOTE: Should move to InputManager later
        InputState input;

        bool currentEsc = glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS;
        bool currentEnter = glfwGetKey(window, GLFW_KEY_ENTER) == GLFW_PRESS;

        // hold state (for movement etc.)
        input.W = glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS;
        input.A = glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS;
        input.S = glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS;
        input.D = glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS;

        // raw state
        input.Esc = currentEsc;
        input.Enter = currentEnter;

        // TAP (edge detection)
        input.EscPressedThisFrame = currentEsc && !prevEsc;
        input.EnterPressedThisFrame = currentEnter && !prevEnter;

        // store for next frame
        prevEsc = currentEsc;
        prevEnter = currentEnter;


        game.Update(deltaTime, input); 

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        game.Draw();
        
        glfwSwapBuffers(window);
    }
}

/**
 * @brief Initializes GLFW, creates a GLFW window,
 * creates an OpenGL context, and loads GLAD.
 *
 * @return true if initialization succeeded, false otherwise.
 */
void GameWindow::Initialize() {
    std::cout << "Initializing game window... ";

    if (!glfwInit()) {
        throw std::runtime_error("Failed to initialize GLFW!");
    }

    // Set version to 3.3 and core profile
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(1600, 900, "Saivox Engine", NULL, NULL);
    if (!window) {
        glfwTerminate();
        throw std::runtime_error("Failed to create window!");
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        glfwDestroyWindow(window);
        glfwTerminate();
        throw std::runtime_error("Failed to initialize GLAD!");
    }

    /* REFACTOR: Camera stuff that ill look at later
    glfwSetKeyCallback(window, InputManager::KeyCallback);
    glfwSetCursorPosCallback(window, InputManager::MouseCallback);

    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glViewport(0, 0, 1600, 900);
    */

    glEnable(GL_DEPTH_TEST);

    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    

    std::cout << "Success!" << std::endl;
    PrintVersion();
}

/**
 * @brief Safely destroy GLFW window and GLFW terminate for proper cleanup.
 */
void GameWindow::Cleanup() {
    std::cout << "Cleaning up window resources... ";

    if (window) {
        glfwDestroyWindow(window);
    }
    glfwTerminate();

    std::cout << "Success!" << std::endl;
}

/**
 * @brief Logs OpenGL version and GPU renderer to terminal.
 */
void GameWindow::PrintVersion() {
    std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << "\n";

    std::cout << "Renderer: " << glGetString(GL_RENDERER) << "\n";

    std::cout << "Vendor: " << glGetString(GL_VENDOR) << "\n";
}
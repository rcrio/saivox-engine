#include <glad/glad.h> // GLAD needs to be before GLFW
#include <GLFW/glfw3.h>
#include <iostream>

#include "GameWindow.h"
#include "Game.h"
#include "InputState.h"
#include "InputManager.h"


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
    // It'd be nice to take game out but game currently does some graphics and cant be
    Game game;
    float lastFrame = 0.0f;

    // -- MAIN GAME LOOP --
    while (!glfwWindowShouldClose(window) && game.IsRunning()) {
        
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        float currentFrame = glfwGetTime();
        float deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
        
        inputManager.processInput(window);


        game.Update(deltaTime, inputManager.GetInput()); 

        

        int width, height;
        glfwGetFramebufferSize(window, &width, &height);

        float aspect = (float)width / (float)height;
        
        game.Draw(aspect);
        
        glfwSwapBuffers(window);
        glfwPollEvents(); 
    }
}

/**
 * @brief Initializes GLFW, creates a GLFW window,
 * creates an OpenGL context, and loads GLAD.
 *
 * @return true if initialization succeeded, false otherwise.
 */
void GameWindow::Initialize() {
    std::cout << "=== Game window start ===\n";

    std::cout << "Initializing GLFW... ";
    if (!glfwInit()) {
        std::cout << "Failed!\n";
    }
    else {
        std::cout << "Success!\n";
    }

    // Set version to 3.3 and core profile
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    // Create window
    std::cout << "Initializing GLFW window object... ";
    window = glfwCreateWindow(1600, 900, "Saivox Engine", NULL, NULL);
    if (!window) {
        std::cout << "Failed!\n";
        glfwTerminate();
    }
    else {
        std::cout << "Success!\n";
    }

    // Set main context to the current window
    glfwMakeContextCurrent(window);

    glfwSetFramebufferSizeCallback(window, FrameBufferSizeCallback);
    
    // Initialize GLAD
    std::cout << "Initializing GLAD... ";
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed!\n";
        glfwDestroyWindow(window);
        glfwTerminate();
    }
    else {
        std::cout << "Success!\n";
    }

    glViewport(0, 0, 1600, 900);

    glEnable(GL_DEPTH_TEST);

    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    
    std::cout << "=== Game window end ===\n\n\n";
    PrintVersion();
}

void GameWindow::FrameBufferSizeCallback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
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
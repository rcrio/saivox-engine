#include <glad/glad.h> // GLAD needs to be before GLFW
#include <GLFW/glfw3.h>

#include "GameWindow.h"
#include <iostream>


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
    //Game game;
    
    float lastFrame = 0.0f;

    // Game loop here.
    while (!glfwWindowShouldClose(window)) {
        // 1. Calculate deltaTime (time since last frame)
        float currentFrame = glfwGetTime();
        float deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        // 2. Input/Events
        glfwPollEvents(); 

        // 3. Logic
        //game.Update(deltaTime); 

        // 4. Rendering
        glClear(GL_COLOR_BUFFER_BIT); 
        
        //game.Draw();
        
        // Needs to update current presented buffer
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
#include <glad/glad.h> // GLAD needs to be before GLFW
#include <GLFW/glfw3.h>

#include "GameWindow.h"
#include <iostream>

/**
 * @brief Initializes GLFW dependencies, prepares needed variables for
 * the main game loop, and then runs the main game loop.
 */
void GameWindow::Run() {
    // Initialize the window. If false, catches the error and closes the game.
    if (!Initialize()) {
        std::cerr << "Failed to initialize the game." << std::endl;
        return;
    }

    PrintVersion();

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

    Cleanup();
}

/**
 * @brief Initializes GLFW, creates a GLFW window,
 * creates an OpenGL context, and loads GLAD.
 *
 * @return true if initialization succeeded, false otherwise.
 */
bool GameWindow::Initialize() {
    if (!glfwInit()) {
        return false;
    }

    // Set window hints if needed (e.g., OpenGL version)
    window = glfwCreateWindow(1600, 900, "Saivox Engine", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return false;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return false;
    }

    // Set a background color (Dark Gray)
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

    return true;
}

/**
 * @brief Safely destroy GLFW window and GLFW terminate for proper cleanup.
 */
void GameWindow::Cleanup() {
    if (window) {
        glfwDestroyWindow(window);
    }
    glfwTerminate();
}

/**
 * @brief Logs OpenGL version and GPU renderer to terminal.
 */
void GameWindow::PrintVersion() {
    const GLubyte* version = glGetString(GL_VERSION);
    const GLubyte* renderer = glGetString(GL_RENDERER);

    std::cout << "Running OpenGL version: " << version << std::endl;
    std::cout << "Running OpenGL renderer: " << renderer << std::endl;
}
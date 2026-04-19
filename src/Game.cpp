#include "Game.h"
#include "Renderer.h"
#include <iostream>




Game::Game() {
    currentState = State::MENU;
    this->renderer.SetupShaders();
    SetupMesh();
}

void Game::Update(float deltaTime) {
    switch (currentState) {
        case State::MENU:
            break;

        case State::PLAYING:
            break;

        default:
            break;
    }
}

void Game::Draw() {
    switch (currentState) {
        case State::MENU:
            renderer.Draw(VAO1, 1.0f, 0.5f, 0.2f); // Orange

            renderer.Draw(VAO2, 0.2f, 0.5f, 1.0f); // Blue
            break;

        case State::PLAYING:
            break;

        default:
            break;
    }
}

void Game::SetupMesh() {
    float triangle1[] = {
        -0.9f, -0.5f, 0.0f,  // left 
        -0.0f, -0.5f, 0.0f,  // right
        -0.45f, 0.5f, 0.0f   // top 
    };

    float triangle2[] = {
         0.0f, -0.5f, 0.0f,  // left
         0.9f, -0.5f, 0.0f,  // right
         0.45f, 0.5f, 0.0f   // top
    };

    renderer.CreateMesh(VAO1, VBO1, triangle1, sizeof(triangle1));
    renderer.CreateMesh(VAO2, VBO2, triangle2, sizeof(triangle2));
}


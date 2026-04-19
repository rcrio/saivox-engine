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
            if (triangle1 && triangle2) {
                renderer.Draw(*triangle1, 1.0f, 0.5f, 0.2f);
                renderer.Draw(*triangle2, 0.2f, 0.5f, 1.0f);
            }
            
            break;

        case State::PLAYING:
            break;

        default:
            break;
    }
}

void Game::SetupMesh()
{
    float tri1Vertices[] = {
        -0.9f, -0.5f, 0.0f,
        -0.0f, -0.5f, 0.0f,
        -0.45f, 0.5f, 0.0f
    };

    float tri2Vertices[] = {
         0.0f, -0.5f, 0.0f,
         0.9f, -0.5f, 0.0f,
         0.45f, 0.5f, 0.0f
    };

    triangle1 = std::make_unique<Mesh>(tri1Vertices, sizeof(tri1Vertices));
    triangle2 = std::make_unique<Mesh>(tri2Vertices, sizeof(tri2Vertices));
}


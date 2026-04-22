#include <iostream>
#include <glm/glm.hpp> 

#include "Game.h"
#include "Shader.h"
#include "Renderer.h"
#include "Texture.h"

Game::Game()
{
    currentState = State::MENU;
}

void Game::Init() {
    
    SetUpMesh();
    /*
    Texture texture;
    texture.Bind();
    texture.LoadFromFile("../../grass_block_side.png");
    */
}

bool Game::IsRunning() const {
    return currentState != State::EXIT;
}

void Game::Update(float deltaTime, const InputState& input)
{
    switch (currentState) {
        case State::MENU:
            if (input.Enter) {
                currentState = State::PLAYING;
            }
            if (input.EscPressedThisFrame) {
                currentState = State::EXIT;
            }
            
            break;

        case State::PLAYING:
        {
            if (input.EscPressedThisFrame) {
                currentState = State::MENU;
            }
            break;
        }
        
        case State::EXIT:
            return;

        default:
            return;
    }
}

void Game::Draw(Shader &shader, float aspect)
{
    switch (currentState)
    {
        case State::MENU:
            break;

        case State::PLAYING:
        {
            if (squareMesh)
            {   
                // Messy, refactor
                renderer.Draw(shader.GetShaderProgram(), *squareMesh);
            }
            break;
        }

        case State::EXIT:
            return;

        default:
            return;
    }
}

// REFACTOR NOTE: Should move this out into perhaps a mesh manager
void Game::SetUpMesh()
{
    float vertices[] = {
         0.5f,  0.5f, 0.0f,  // top right
         0.5f, -0.5f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f,  // bottom left
        -0.5f,  0.5f, 0.0f   // top left 
    };
    unsigned int indices[] = {  // note that we start from 0!
        0, 1, 3,  // first Triangle
        1, 2, 3   // second Triangle
    };

    squareMesh = std::make_unique<Mesh>(
        vertices, sizeof(vertices),
        indices, sizeof(indices)
    );
}
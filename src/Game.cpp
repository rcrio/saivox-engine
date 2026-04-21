#include <iostream>
#include <glm/glm.hpp> 

#include "Game.h"
#include "Renderer.h"

Game::Game() {
    currentState = State::MENU;
    renderer = std::make_unique<Renderer>();
    renderer->SetupShaders();
    camera = std::make_unique<Camera>();
    // REFACTOR NOTE: If you call game in GameWindow, it tries to setup mesh and crashes
    SetupMesh();
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
            UpdateCamera(deltaTime, input);
            UpdateCameraLook(input);
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

void Game::Draw(float aspect)
{
    switch (currentState)
    {
        case State::MENU:
            break;

        case State::PLAYING:
        {
            if (cubeMesh)
            {
                renderer->Draw(*cubeMesh, 1.0f, 0.5f, 0.2f);
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
void Game::SetupMesh()
{
    // 8 unique corners of a cube
    float cubeVertices[] = {
        -0.5f, -0.5f,  0.5f, // 0: Front-bottom-left
         0.5f, -0.5f,  0.5f, // 1: Front-bottom-right
         0.5f,  0.5f,  0.5f, // 2: Front-top-right
        -0.5f,  0.5f,  0.5f, // 3: Front-top-left
        -0.5f, -0.5f, -0.5f, // 4: Back-bottom-left
         0.5f, -0.5f, -0.5f, // 5: Back-bottom-right
         0.5f,  0.5f, -0.5f, // 6: Back-top-right
        -0.5f,  0.5f, -0.5f  // 7: Back-top-left
    };

    // Instructions on how to connect the 8 dots into 12 triangles
    unsigned int cubeIndices[] = {
        // Front face
        0, 1, 2, 2, 3, 0,
        // Right face
        1, 5, 6, 6, 2, 1,
        // Back face
        7, 6, 5, 5, 4, 7,
        // Left face
        4, 0, 3, 3, 7, 4,
        // Top face
        3, 2, 6, 6, 7, 3,
        // Bottom face
        4, 5, 1, 1, 0, 4
    };

    cubeMesh = std::make_unique<Mesh>(
        cubeVertices, sizeof(cubeVertices), 
        cubeIndices, sizeof(cubeIndices)
    );
}

// REFACTOR NOTE: Move to Camera Controller later
void Game::UpdateCamera(float deltaTime, const InputState& input)
{
    

    float speed = 3.0f * deltaTime;

    glm::vec3 position = camera->GetPosition();
    glm::vec3 front = camera->GetFront();

    glm::vec3 right = glm::normalize(
        glm::cross(front, glm::vec3(0, 1, 0))
    );

    if (input.W) position += front * speed;
    if (input.S) position -= front * speed;
    if (input.D) position += right * speed;
    if (input.A) position -= right * speed;

    camera->SetPosition(position);
}


void Game::UpdateCameraLook(const InputState& input)
{
    std::cout << input.mouseDeltaX << ", " << input.mouseDeltaY << "\n";
    
    static float yaw = -90.0f;
    static float pitch = 0.0f;

    float sensitivity = 0.05f;

    float xoffset = input.mouseDeltaX * sensitivity;
    float yoffset = input.mouseDeltaY * sensitivity;

    // safety clamp
    xoffset = glm::clamp(xoffset, -5.0f, 5.0f);
    yoffset = glm::clamp(yoffset, -5.0f, 5.0f);

    yaw += xoffset;
    pitch += yoffset;

    if (pitch > 89.0f) pitch = 89.0f;
    if (pitch < -89.0f) pitch = -89.0f;

    glm::vec3 direction;
    direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    direction.y = sin(glm::radians(pitch));
    direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));

    camera->SetFront(glm::normalize(direction));
}

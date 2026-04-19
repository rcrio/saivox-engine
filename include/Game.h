#ifndef SAIVOX_ENGINE_GAME_H
#define SAIVOX_ENGINE_GAME_H

#include <memory>
#include <GLFW/glfw3.h>

#include "Renderer.h"
#include "InputState.h"
#include "Camera.h"

class Game {
public:
    enum class State {
        MENU,
        PLAYING,
        EXIT
    };

    Game();

    void Update(float deltaTime, const InputState& input);
    void Draw(float aspect);
    bool IsRunning() const;
    // REFACTOR NOTE: Move this out
    void SetupMesh();
    
private:
    State currentState;

    std::unique_ptr<Camera> camera;
    
    std::unique_ptr<Mesh> cubeMesh;

    std::unique_ptr<Renderer> renderer;
};


#endif
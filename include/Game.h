#ifndef SAIVOX_ENGINE_GAME_H
#define SAIVOX_ENGINE_GAME_H

#include <memory>


#include "Shader.h"
#include "Renderer.h"
#include "InputState.h"


class Game {
public:
    enum class State {
        MENU,
        PLAYING,
        EXIT
    };

    Game();
    /// @brief Currently sets up shaders and sets up mesh.
    void Init();
    void Update(float deltaTime, const InputState& input);
    void Draw(float aspect);
    bool IsRunning() const;
    // REFACTOR NOTE: Move this out
    void SetUpMesh();

private:
    State currentState;

    Shader shader;

    Renderer renderer;
    
    std::unique_ptr<Mesh> squareMesh;

    
};


#endif
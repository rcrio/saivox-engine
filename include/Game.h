#ifndef SAIVOX_ENGINE_GAME_H
#define SAIVOX_ENGINE_GAME_H

#include <memory>
#include <GLFW/glfw3.h>

#include "Renderer.h"

class Game {
public:
    enum class State {
        MENU,
        PLAYING,
        EXIT
    };

    Game();

    void Update(float deltaTime);
    void Draw();
    
private:
    void SetupMesh();

    State currentState;

    std::unique_ptr<Mesh> triangle1;
    std::unique_ptr<Mesh> triangle2;

    Renderer renderer;
};


#endif
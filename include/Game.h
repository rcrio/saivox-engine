#ifndef SAIVOX_ENGINE_GAME_H
#define SAIVOX_ENGINE_GAME_H

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
    State currentState;
    Renderer renderer;
    unsigned int VAO1, VBO1;
    unsigned int VAO2, VBO2;

    void SetupMesh();
};


#endif
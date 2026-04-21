#pragma once

struct InputState {
    bool W = false;
    bool A = false;
    bool S = false;
    bool D = false;
    bool Enter = false;
    bool Esc = false;

    bool EnterPressedThisFrame = false;
    bool EscPressedThisFrame = false;

    float mouseDeltaX = 0.0f;
    float mouseDeltaY = 0.0f;
};
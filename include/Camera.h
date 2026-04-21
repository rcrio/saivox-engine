#pragma once

#include <glm/glm.hpp>

#include "InputState.h"

class Camera {
public:
    Camera();

    void ProcessMouse(float deltaX, float deltaY);
    void ProcessKeyboard(float deltaTime, const InputState& input);

    glm::mat4 GetViewMatrix() const;
    glm::mat4 GetProjectionMatrix(float aspectRatio) const;

    void SetPosition(const glm::vec3& position);
    void SetFront(const glm::vec3& front);
    void SetUp(const glm::vec3& up);

    const glm::vec3& GetPosition() const;
    const glm::vec3& GetFront() const;

private:
    glm::vec3 position;
    glm::vec3 front;
    glm::vec3 up;

    float yaw;
    float pitch;
};
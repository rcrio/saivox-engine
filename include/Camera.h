#pragma once

#include <glm/glm.hpp>

class Camera {
public:
    Camera();

    glm::mat4 GetViewMatrix() const;

    void SetPosition(const glm::vec3& position);
    void SetFront(const glm::vec3& front);
    void SetUp(const glm::vec3& up);

    const glm::vec3& GetPosition() const;
    const glm::vec3& GetFront() const;

private:
    glm::vec3 position;
    glm::vec3 front;
    glm::vec3 up;
};
#include "Camera.h"
#include <glm/gtc/matrix_transform.hpp>

Camera::Camera()
    : position(0.0f, 0.0f, 3.0f),
      front(0.0f, 0.0f, -1.0f),
      up(0.0f, 1.0f, 0.0f)
{
}

glm::mat4 Camera::GetViewMatrix() const {
    return glm::lookAt(position, position + front, up);
}

void Camera::SetPosition(const glm::vec3& p) {
    position = p;
}

void Camera::SetFront(const glm::vec3& f) {
    front = f;
}

void Camera::SetUp(const glm::vec3& u) {
    up = u;
}

const glm::vec3& Camera::GetPosition() const {
    return position;
}

const glm::vec3& Camera::GetFront() const {
    return front;
}
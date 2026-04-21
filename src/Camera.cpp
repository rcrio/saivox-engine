#include "Camera.h"
#include "InputState.h"
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

glm::mat4 Camera::GetProjectionMatrix(float aspectRatio) const {
    return glm::perspective(
        glm::radians(45.0f),
        aspectRatio,
        0.1f,
        100.0f
    );
}

void Camera::ProcessMouse(float deltaX, float deltaY)
{
    float sensitivity = 0.1f;

    yaw   += deltaX * sensitivity;
    pitch += deltaY * sensitivity;

    // Clamp pitch (prevents flipping)
    if (pitch > 89.0f) pitch = 89.0f;
    if (pitch < -89.0f) pitch = -89.0f;

    // Recalculate front vector
    glm::vec3 direction;
    direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    direction.y = sin(glm::radians(pitch));
    direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));

    front = glm::normalize(direction);
}

void Camera::ProcessKeyboard(float deltaTime, const InputState& input)
{
    float speed = 5.0f * deltaTime;

    glm::vec3 right = glm::normalize(glm::cross(front, up));

    if (input.W)
        position += speed * front;

    if (input.S)
        position -= speed * front;

    if (input.A)
        position -= right * speed;

    if (input.D)
        position += right * speed;
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
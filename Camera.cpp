#include "Camera.h"

Camera::Camera() {
	pos = glm::vec3(-3.0f, 0.0f, 0.3f);
	front = glm::vec3(1.0f, 0.0f, 0.0f);
	up = glm::vec3(0.0f, 0.0f, 1.0f);
}

Camera::Camera(glm::vec3 cPos) {
	pos = cPos;
	front = glm::vec3(1.0f, 0.0f, 0.0f);
	up = glm::vec3(0.0f, 0.0f, 1.0f);
}

Camera::Camera(glm::vec3 cPos, glm::vec3 cFront) {
	pos = cPos;
	front = cFront;
	up = glm::vec3(0.0f, 0.0f, 1.0f);
}

glm::vec3 Camera::getPosition() {
	return pos;
}

void Camera::setPosition(glm::vec3 newPosition) {
	pos = newPosition;
}

glm::vec3 Camera::getFront() {
	return front;
}

void Camera::setFront(glm::vec3 newFront) {
	front = newFront;
}

float Camera::getMovementSpeed() {
	return movementSpeed;
}

void Camera::setMovementSpeed(float newMS) {
	movementSpeed = newMS;
}
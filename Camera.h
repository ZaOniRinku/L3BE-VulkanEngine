#pragma once
#include <glm/glm.hpp>

class Camera{
public:
	Camera();
	Camera(glm::vec3 cPos);
	Camera(glm::vec3 cPos, glm::vec3 cFront);
	glm::vec3 getPosition();
	void setPosition(glm::vec3 newPosition);
	void setPosition(float x, float y, float z);
	glm::vec3 getFront();
	void setFront(glm::vec3 newFront);
	void setFront(float x, float y, float z);
	glm::vec3 getUp();
	float getMovementSpeed();
	void setMovementSpeed(float newMS);
private:
	glm::vec3 pos;
	glm::vec3 front;
	glm::vec3 up;
	float movementSpeed;
};
#pragma once
#include <iostream>
#include "SGNode.h"
#include "Camera.h"

class Scene {
public:
	Scene();
	Scene(Camera sceneCamera);
	SGNode* getRoot();
	void setRoot(SGNode newRoot);
	Camera* getCamera();
	void setCamera(Camera newCamera);
	void viewSceneGraph();
	int nbElements();
	float getAmbientLightValue();
	void setAmbientLightValue(float newAmbientLightValue);
	float getAmbientLightColorR();
	float getAmbientLightColorG();
	float getAmbientLightColorB();
	void setAmbientLightColor(float newR, float newG, float newB);
	float getLightDirectionX();
	float getLightDirectionY();
	float getLightDirectionZ();
	void setLightDirection(float newX, float newY, float newZ);
private:
	SGNode sceneRoot;
	Camera camera;

	// Ambient Light
	float ambientLightValue;
	glm::vec3 ambientLightColor;

	// Directional Light
	glm::vec3 lightDirection;
};
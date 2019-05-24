#include "Scene.h"

Scene::Scene() {
	sceneRoot = SGNode();
	camera = Camera();
	ambientLightValue = 1.0f;
	ambientLightColor = { 0.0f, 0.0f, 1.0f };
	lightDirection = { 1.0f, 1.0f, 1.0f };
}

Scene::Scene(Camera sceneCamera) {
	sceneRoot = SGNode();
	camera = sceneCamera;
	ambientLightValue = 1.0f;
	ambientLightColor = { 1.0f, 1.0f, 1.0f };
	lightDirection = { 1.0f, 1.0f, 1.0f };
}

SGNode* Scene::getRoot() {
	return &sceneRoot;
}

void Scene::setRoot(SGNode newRoot) {
	sceneRoot = newRoot;
}

Camera* Scene::getCamera() {
	return &camera;
}

void Scene::setCamera(Camera newCamera) {
	camera = newCamera;
}

void Scene::viewSceneGraph() {
	std::cout << "Scene" << std::endl;
	sceneRoot.viewSceneNode(1);
}

int Scene::nbElements() {
	return sceneRoot.nbElements();
}

float Scene::getAmbientLightValue() {
	return ambientLightValue;
}

void Scene::setAmbientLightValue(float newAmbientLightValue) {
	ambientLightValue = newAmbientLightValue;
}

float Scene::getAmbientLightColorR() {
	return ambientLightColor.x;
}

float Scene::getAmbientLightColorG() {
	return ambientLightColor.y;
}

float Scene::getAmbientLightColorB() {
	return ambientLightColor.z;
}

void Scene::setAmbientLightColor(float newR, float newG, float newB) {
	ambientLightColor = { newR, newG, newB };
}

float Scene::getLightDirectionX() {
	return lightDirection.x;
}

float Scene::getLightDirectionY() {
	return lightDirection.y;
}

float Scene::getLightDirectionZ() {
	return lightDirection.z;
}

void Scene::setLightDirection(float newX, float newY, float newZ) {
	lightDirection = { newX, newY, newZ };
}
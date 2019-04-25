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
private:
	SGNode sceneRoot;
	Camera camera;
};
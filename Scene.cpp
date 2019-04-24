#include "SGNode.h"

class Scene {
public:
	Scene() {
		sceneRoot = SGNode();
	}

	SGNode getRoot() {
		return sceneRoot;
	}

	void setRoot(SGNode newRoot) {
		sceneRoot = newRoot;
	}
private:
	SGNode sceneRoot;
};
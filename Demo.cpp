#include "Scene.h"
#include "SGNode.h"
#include "Object.h"
#include "Camera.h"

Scene scene;

int main(void) {
	// DEMO
	// In this demo, Scene Graph Nodes must be created explicitly, 
	// but in an editor with a UI, SG Nodes can be created automatically 
	// when an instance is placed inside a scene, according to the instances hierarchy.

	// Scene creation (default Camera)
	scene = Scene();

	// Ground object
	Object ground = Object("models/plan.obj", "textures/textureplan.jpg", 0.0f, 0.0f, 0.0f, 10.0f);
	SGNode groundNode = SGNode(&ground);
	scene.getRoot()->addChild(&groundNode);

	// Table object
	Object table = Object("models/table.obj", "textures/table.png", 0.0f, 0.1f, 0.0f, 0.5f);
	SGNode tableNode = SGNode(&table);
	groundNode.addChild(&tableNode);

	// Dice 1 object
	Object dice1 = Object("models/dice.obj", "textures/texturede.png", -1.8f, 10.4f, -3.5f, 0.07f);
	SGNode dice1Node = SGNode(&dice1);
	tableNode.addChild(&dice1Node);

	// Dice 2 object
	Object dice2 = Object("models/dice.obj", "textures/texturede.png", 4.5f, 10.4f, 3.2f, 0.07f);
	SGNode dice2Node = SGNode(&dice2);
	tableNode.addChild(&dice2Node);

	// Dice 3 object
	Object dice3 = Object("models/dice.obj", "textures/texturede.png", 2.4f, 10.4f, 4.1f, 0.07f);
	SGNode dice3Node = SGNode(&dice3);
	scene.getRoot()->addChild(&dice3Node);

	// Visualize hierarchy
	scene.viewSceneGraph();

	// Launch application

	return 0;
}
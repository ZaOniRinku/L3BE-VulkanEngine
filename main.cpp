#include "GraphicsEngine.h"

int main() {
	// DEMO
	// In this demo, Scene Graph Nodes must be created explicitly, 
	// but in an editor with a UI, SG Nodes can be created automatically 
	// when an instance is placed inside a scene, according to the instances hierarchy.

	// Scene creation (default Camera)
	Scene scene = Scene();
	scene.setAmbientLightColor(1.0f, 1.0f, 1.0f);
	scene.setAmbientLightValue(0.5f);

	// Ground object
	Object ground = Object("models/plan.obj", "textures/textureplan.jpg", 0.0f, 0.0f, -0.1f, 30.0f);
	SGNode groundNode = SGNode(&ground);
	scene.getRoot()->addChild(&groundNode);

	// Table object
	Object table = Object("models/table.obj", "textures/table.png", 0.0f, 0.1f, 0.0f, 0.5f);
	SGNode tableNode = SGNode(&table);
	groundNode.addChild(&tableNode);

	// Dice 1 object
	Object dice1 = Object("models/dice.obj", "textures/texturede.png", -0.2f, 0.5f, 0.7f, 0.1f);
	SGNode dice1Node = SGNode(&dice1);
	tableNode.addChild(&dice1Node);

	// Dice 2 object
	Object dice2 = Object("models/dice.obj", "textures/texturede.png", 0.0f, 0.0f, 0.7f, 0.1f);
	SGNode dice2Node = SGNode(&dice2);
	tableNode.addChild(&dice2Node);

	// Dice 3 object
	Object dice3 = Object("models/dice.obj", "textures/texturede.png", 1.0f, 0.0f, -0.04, 0.1f);
	SGNode dice3Node = SGNode(&dice3);
	groundNode.addChild(&dice3Node);

	// Arrow object
	Object arrow = Object("models/arrow.obj", "textures/arrow.png", 5.5f, 6.5f, 12.2f, 0.4f);
	SGNode arrowNode = SGNode(&arrow);
	scene.getRoot()->addChild(&arrowNode);

	// Skybox object
	Object skybox = Object("models/skybox.obj", "textures/skyboxspace.png", 0.0f, 0.0f, 0.0f, 55.0f, 90.0f, 0.0f, 0.0f);
	SGNode skyboxNode = SGNode(&skybox);
	scene.getRoot()->addChild(&skyboxNode);

	// House object
	Object house = Object("models/maison.obj", "textures/maison.png", 4.0f, 3.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f);
	SGNode houseNode = SGNode(&house);
	groundNode.addChild(&houseNode);

	// Visualize hierarchy
	scene.viewSceneGraph();

	GraphicsEngine app;

	// Set the scene
	app.setScene(&scene);
	// Start the application
	app.start();
}
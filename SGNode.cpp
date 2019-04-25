#include "SGNode.h"

SGNode::SGNode() {
	object = nullptr;
}

SGNode::SGNode(Object* obj) {
	object = obj;
	obj->setNode(this);
}

void SGNode::addChild(SGNode* child) {
	children.push_back(child);
}

std::vector<SGNode*> SGNode::getChildren() {
	return children;
}

SGNode* SGNode::getParent() {
	return parent;
}
void SGNode::setParent(SGNode newParent) {
	parent = &newParent;
}

Object* SGNode::getObject() {
	return object;
}

void SGNode::setObject(Object newObject) {
	*object = newObject;
}

void SGNode::viewSceneNode(int level) {
	for (SGNode* child : children) {
		for (size_t i = 0; i < level; i++) {
			std::cout << "-";
		}
		if (child->object != nullptr) {
			std::cout << " " << child->object->getModelPath() << std::endl;
		}
		child->viewSceneNode(level + 1);
	}
}
#pragma once
#include <vector>
#include "Object.h"

class SGNode {
public:
	void addChild(SGNode child);
	std::vector<SGNode> getChildren();
	Object getObject();
	void setObject(Object newObject);
};
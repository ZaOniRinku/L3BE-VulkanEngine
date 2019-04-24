#include "SGNode.h"

/* Element of a Scene Graph */
class SGNode {
public:
	void addChild(SGNode child) {
		children.push_back(child);
	}

	std::vector<SGNode> getChildren() {
		return children;
	}

	Object getObject() {
		return object;
	}

	void setObject(Object newObject) {
		object = newObject;
	}
private:
	std::vector<SGNode> children;
	Object object;
};
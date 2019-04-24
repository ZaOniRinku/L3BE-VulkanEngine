#pragma once
#include <iostream>
#include <glm/glm.hpp>
#include <unordered_map>
#include <tiny_obj_loader.h>

struct Vertex {
	glm::vec3 pos;
	glm::vec3 color;
	glm::vec2 texCoord;

	bool operator==(const Vertex& other) const {
		return pos == other.pos && color == other.color && texCoord == other.texCoord;
	}
};

class Object {
public:
	Object(std::string mPath, std::string tPath, float x, float y, float z, float mScale);
private:
	void loadModel();
};
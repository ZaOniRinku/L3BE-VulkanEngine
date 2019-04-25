#pragma once
#include <iostream>
#include <glm/glm.hpp>
#include <unordered_map>
#include <glm/gtx/hash.hpp>
//#include <tiny_obj_loader.h>
#include "SGNode.h"
#define GLM_ENABLE_EXPERIMENTAL
//#define TINYOBJLOADER_IMPLEMENTATION

struct Vertex {
	glm::vec3 pos;
	glm::vec3 color;
	glm::vec2 texCoord;

	bool operator==(const Vertex& other) const {
		return pos == other.pos && color == other.color && texCoord == other.texCoord;
	}
};

namespace std {
	template<> struct hash<Vertex> {
		size_t operator()(Vertex const& vertex) const {
			return ((hash<glm::vec3>()(vertex.pos) ^
				(hash<glm::vec3>()(vertex.color) << 1)) >> 1) ^
				(hash<glm::vec2>()(vertex.texCoord) << 1);
		}
	};
}

class SGNode;

class Object {
public:
	Object();
	Object(std::string mPath, std::string tPath, glm::vec3 oPos, float mScale);
	Object(std::string mPath, std::string tPath, float x, float y, float z, float mScale);
	void move(glm::vec3 movePosition);
	void move(float x, float y, float z);
	void rescale(float newScale);
	glm::vec3 getPosition();
	float getScale();
	SGNode* getNode();
	void setNode(SGNode* newNode);
	std::string getModelPath();
private:
	//void loadModel();
	// Object's attributes
	std::string modelPath;
	std::string texturePath;
	glm::vec3 pos;
	float scale;

	SGNode* node;

	// Model attributes
	std::vector<Vertex> modelVertices;
	std::vector<uint32_t> modelIndices;
};
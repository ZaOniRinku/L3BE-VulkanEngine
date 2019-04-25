#include "Object.h"

Object::Object() {}

Object::Object(std::string mPath, std::string tPath, glm::vec3 oPos, float mScale) {
	modelPath = mPath;
	texturePath = tPath;
	pos = oPos;
	scale = mScale;
	//loadModel();
	node = nullptr;
}

Object::Object(std::string mPath, std::string tPath, float x, float y, float z, float mScale) {
	modelPath = mPath;
	texturePath = tPath;
	pos = {x, y, z};
	scale = mScale;
	//loadModel();
	node = nullptr;
}
/*
void Object::move(glm::vec3 movePosition) {
	for (Vertex vertex : modelVertices) {
		vertex.pos = vertex.pos + (movePosition * scale);
	}
	for (SGNode* child : node->getChildren()) {
		child->getObject()->move(movePosition);
	}
}

void Object::move(float x, float y, float z) {
	for (Vertex vertex : modelVertices) {
		vertex.pos = { vertex.pos.x + (x * scale), vertex.pos.y + (y * scale), vertex.pos.z + (z * scale) };
	}
	for (SGNode* child : node->getChildren()) {
		child->getObject()->move(x, y, z);
	}
}
*/
void Object::rescale(float newScale) {
	for (Vertex vertex : modelVertices) {
		vertex.pos = (vertex.pos / scale) * newScale;
	}
}

glm::vec3 Object::getPosition() {
	return pos;
}

float Object::getScale() {
	return scale;
}

SGNode* Object::getNode() {
	return node;
}

void Object::setNode(SGNode* newNode) {
	node = newNode;
}

std::string Object::getModelPath() {
	return modelPath;
}

/*void Object::loadModel() {
	tinyobj::attrib_t attrib;
	std::vector<tinyobj::shape_t> shapes;
	std::vector<tinyobj::material_t> materials;
	std::string warn, err;

	if (!tinyobj::LoadObj(&attrib, &shapes, &materials, &warn, &err, modelPath.c_str())) {
		throw std::runtime_error(warn + err);
	}

	std::unordered_map<Vertex, uint32_t> uniqueVertices = {};

	for (const auto& shape : shapes) {
		for (const auto& index : shape.mesh.indices) {
			Vertex vertex = {};
			vertex.pos = {
				(attrib.vertices[3 * index.vertex_index + 0] + pos.x) * scale,
				(attrib.vertices[3 * index.vertex_index + 1] + pos.y) * scale,
				(attrib.vertices[3 * index.vertex_index + 2] + pos.z) * scale
			};
			vertex.texCoord = {
				attrib.texcoords[2 * index.texcoord_index + 0],
				1.0f - attrib.texcoords[2 * index.texcoord_index + 1]
			};
			vertex.color = {
				1.0f,
				1.0f,
				1.0f
			};

			if (uniqueVertices.count(vertex) == 0) {
				uniqueVertices[vertex] = static_cast<uint32_t>(modelVertices.size());
				modelVertices.push_back(vertex);
			}
			modelIndices.push_back(uniqueVertices[vertex]);
		}
	}
}*/
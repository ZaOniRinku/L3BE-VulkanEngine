#include "Object.h"

class Object {
public:
	Object(std::string mPath, std::string tPath, float x, float y, float z, float mScale) {
		modelPath = mPath;
		texturePath = tPath;
		pos = {x, y, z};
		scale = mScale;
		loadModel();
	}

private:
	// Object's attributes
	std::string modelPath;
	std::string texturePath;
	glm::vec3 pos;
	float scale;

	// Model attributes
	std::vector<Vertex> modelVertices;
	std::vector<uint32_t> modelIndices;

	void loadModel() {
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
	}
};
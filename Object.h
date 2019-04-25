#pragma once
#include <vulkan/vulkan.hpp>
#include <iostream>
#include <glm/glm.hpp>
#include <unordered_map>
#include <glm/gtx/hash.hpp>
#include "SGNode.h"
#define GLM_ENABLE_EXPERIMENTAL

struct Vertex {
	glm::vec3 pos;
	glm::vec3 color;
	glm::vec2 texCoord;

	static VkVertexInputBindingDescription getBindingDescription() {
		VkVertexInputBindingDescription bindingDescription = {};
		bindingDescription.binding = 0;
		bindingDescription.stride = sizeof(Vertex);
		bindingDescription.inputRate = VK_VERTEX_INPUT_RATE_VERTEX;

		return bindingDescription;
	}

	static std::array<VkVertexInputAttributeDescription, 3> getAttributeDescriptions() {
		std::array<VkVertexInputAttributeDescription, 3> attributeDescriptions = {};
		attributeDescriptions[0].binding = 0;
		attributeDescriptions[0].location = 0;
		attributeDescriptions[0].format = VK_FORMAT_R32G32B32_SFLOAT;
		attributeDescriptions[0].offset = offsetof(Vertex, pos);

		attributeDescriptions[1].binding = 0;
		attributeDescriptions[1].location = 1;
		attributeDescriptions[1].format = VK_FORMAT_R32G32B32_SFLOAT;
		attributeDescriptions[1].offset = offsetof(Vertex, color);

		attributeDescriptions[2].binding = 0;
		attributeDescriptions[2].location = 2;
		attributeDescriptions[2].format = VK_FORMAT_R32G32_SFLOAT;
		attributeDescriptions[2].offset = offsetof(Vertex, texCoord);

		return attributeDescriptions;
	}

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
	std::string getTexturePath();
	std::vector<Vertex> getModelVertices();
	std::vector<uint32_t> getModelIndices();
	VkBuffer& getVertexBuffer();
	VkDeviceMemory& getVertexBufferMemory();
	VkBuffer& getIndexBuffer();
	VkDeviceMemory& getIndexBufferMemory();
	uint32_t getMipLevel();
	void setMipLevel(uint32_t newMipLevel);
	VkImage& getTextureImage();
	void setTextureImage(VkImage newTextureImage);
	VkDeviceMemory& getTextureImageMemory();
	void setTextureImageMemory(VkDeviceMemory newTextureImageMemory);
	VkImageView& getTextureImageView();
	void setTextureImageView(VkImageView newTextureImageView);
	VkSampler& getTextureSampler();
	void setTextureSampler(VkSampler newTextureSampler);
	VkDescriptorSet& getDescriptorSet();
private:
	// Object's attributes
	std::string modelPath;
	std::string texturePath;
	glm::vec3 pos;
	float scale;

	SGNode* node;

	// Model attributes
	std::vector<Vertex> modelVertices;
	std::vector<uint32_t> modelIndices;
	VkBuffer vertexBuffer;
	VkDeviceMemory vertexBufferMemory;
	VkBuffer indexBuffer;
	VkDeviceMemory indexBufferMemory;

	// Texture attributes
	VkImage textureImage;
	VkDeviceMemory textureImageMemory;
	VkImageView textureImageView;
	VkSampler textureSampler;
	uint32_t mipLevel;

	VkDescriptorSet descriptorSet;
};
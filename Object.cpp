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

std::string Object::getTexturePath() {
	return texturePath;
}

std::vector<Vertex> Object::getModelVertices() {
	return modelVertices;
}

std::vector<uint32_t> Object::getModelIndices() {
	return modelIndices;
}

VkBuffer& Object::getVertexBuffer() {
	return vertexBuffer;
}

VkDeviceMemory& Object::getVertexBufferMemory() {
	return vertexBufferMemory;
}

VkBuffer& Object::getIndexBuffer() {
	return indexBuffer;
}

VkDeviceMemory& Object::getIndexBufferMemory() {
	return indexBufferMemory;
}

uint32_t Object::getMipLevel() {
	return mipLevel;
}

void Object::setMipLevel(uint32_t newMipLevel) {
	mipLevel = newMipLevel;
}

VkImage& Object::getTextureImage() {
	return textureImage;
}

void Object::setTextureImage(VkImage newTextureImage) {
	textureImage = newTextureImage;
}

VkDeviceMemory& Object::getTextureImageMemory() {
	return textureImageMemory;
}

void Object::setTextureImageMemory(VkDeviceMemory newTextureImageMemory) {
	textureImageMemory = newTextureImageMemory;
}

VkImageView& Object::getTextureImageView() {
	return textureImageView;
}

void Object::setTextureImageView(VkImageView newTextureImageView) {
	textureImageView = newTextureImageView;
}

VkSampler& Object::getTextureSampler() {
	return textureSampler;
}

void Object::setTextureSampler(VkSampler newTextureSampler) {
	textureSampler = newTextureSampler;
}

VkDescriptorSet& Object::getDescriptorSet() {
	return descriptorSet;
}
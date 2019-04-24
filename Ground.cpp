#include "Object.h"

class Ground : public Object {
public:
	Ground(float x, float y, float z, float mScale) : Object(modelPath, texturePath, x, y, z, mScale) {}
private:
	std::string modelPath = "models/plan.obj";
	std::string texturePath = "textures/textureplan.jpg";
};
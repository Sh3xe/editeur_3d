#pragma once

#include <glm/glm.hpp>

class Camera
{
public:
	Camera() {}
	~Camera() {}

	glm::mat4 get_view();

	glm::vec3 pos {0.0f, 0.0f, 0.0f};
	float rx {0.0f}, ry {0.0f};
	float sensitivity {1.0f};
};
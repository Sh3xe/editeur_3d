#include "camera.hpp"
#include <glm/ext.hpp>

glm::mat4 Camera::get_view()
{
	//glm::vec3 dir {cos(rx), 0.0f, sin(rx)};
	return glm::lookAt(pos, /*pos + dir*/ glm::vec3{0.0f, 0.0f, 0.0f}, glm::vec3{0.0f, 1.0f, 0.0f});
}
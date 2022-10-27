#pragma once

#include <glm/glm.hpp>

class Camera
{
public:
	Camera() {}
	~Camera() {}

	void translate( float x, float y );
	void rotate( float x, float y );
	void zoom( float z );

	glm::mat4 get_view() const;
	glm::vec3 get_pos() const { return m_pos; };

private:
	glm::vec3 m_center {0.0f, 0.0f, 0.0f};
	glm::vec3 m_pos {1.0f, 0.0f, 0.0f};
	glm::vec3 m_up{0.0f, 1.0f, 0.0f};
	float m_rx {0.0f}, m_ry {0.0f};
	float m_zoom {1.0f};
};
#include "camera.hpp"
#include <glm/ext.hpp>
#include "core/logger.hpp"
#include <cmath>

void Camera::translate( float x, float y )
{
}

void Camera::rotate( float x, float y )
{
	m_rx += x;
	m_ry += y;
}

void Camera::zoom( float z )
{
}

glm::mat4 Camera::get_view() const
{
	float dist_to_center = glm::length(m_center - m_pos);
	glm::vec3 rot = glm::vec3{cos(m_ry)*cos(m_rx), sin(m_ry), cos(m_ry)*sin(m_rx)} * dist_to_center;
	return glm::lookAt(m_center + rot, m_center, m_up);
}
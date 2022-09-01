#pragma once

#include "shader.hpp"

#include <cstdint>
#include <glm/glm.hpp>
#include <vector>

struct Vertex
{
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec2 text_coords;
};

struct Transform
{
	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scale;
};

class Mesh
{
public:
	friend class Renderer;

	Mesh(const std::vector<Vertex> &data, bool cull = false);
	~Mesh();

public:
	Transform m_transform;

private:
	void upload();

	uint32_t m_vao, m_vbo;
	std::vector<Vertex> m_vertices;
	bool m_cull;
};

Mesh create_cube();
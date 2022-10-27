#pragma once

#include "shader.hpp"

#include <cstdint>
#include <glm/glm.hpp>
#include <vector>

struct Vertex
{
	float x, y, z;
	float nx, ny, nz;
	float tx, ty;
};

struct Transform
{
	glm::vec3 position = {0.0f, 0.0f, 0.0f};
	glm::vec3 rotation = {0.0f, 0.0f, 0.0f};
	glm::vec3 scale    = {1.0f, 1.0f, 1.0f};
};

class Mesh
{
public:
	friend class Renderer;

	Mesh(const std::vector<Vertex> &data, bool cull = false);
	~Mesh();

	glm::mat4 get_model_matrix() const { return m_model; }
	void update_model_matrix();

public:
	Transform m_transform;

private:
	void upload();

	glm::mat4 m_model;
	uint32_t m_vao, m_vbo;
	std::vector<Vertex> m_vertices;
	bool m_cull;
};

std::vector<Vertex> create_cube();
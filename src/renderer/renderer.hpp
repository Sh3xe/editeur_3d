#pragma once

#include <memory>
#include <vector>
#include <glm/glm.hpp>
#include "shader.hpp"
#include "texture2d.hpp"
#include "mesh.hpp"
#include "camera.hpp"

enum class RenderMode
{
	TEXTURED,
	LIGHT,
	WIREFRAME
};

class Renderer
{
public:
	Renderer() {}
	~Renderer() {}

	bool init();
	void shutdown();

	void on_resize(int width, int height);

	void begin_scene();
	void end_scene(const Camera &cam, RenderMode render_mode);
	void submit(std::shared_ptr<Mesh> mesh);

private:
	std::vector< std::shared_ptr<Mesh> > m_meshes;

	std::unique_ptr<Shader> m_light_shader;
	std::unique_ptr<Shader> m_textured_shader;

	glm::mat4 m_projection_matrix;
};
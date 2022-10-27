#include "renderer.hpp"

#include <glm/ext.hpp>
#include "GL/glew.h"
#include "gldebug.hpp"
#include "core/logger.hpp"

bool Renderer::init()
{
	m_light_shader = std::make_unique<Shader>("res/shaders/light.vs", "res/shaders/light.fs");
	m_textured_shader = std::make_unique<Shader>("res/shaders/texture.vs", "res/shaders/texture.fs");

	return (*m_light_shader) && (*m_textured_shader);
}

void Renderer::shutdown()
{
}

void Renderer::on_resize(int width, int height)
{
	glViewport(0, 0, width, height);
	m_projection_matrix = glm::perspective( glm::radians(90.0f), (float)width / (float)height, 0.01f, 100.0f );
	log_gl_errors();
}

void Renderer::begin_scene()
{
	m_meshes.clear();
}

void Renderer::end_scene(const Camera &cam, RenderMode render_mode)
{
	// set the current shader depending on the rendering mode
	Shader *current_shader = nullptr;

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glEnable(GL_CULL_FACE);

	switch (render_mode)
	{
	case RenderMode::LIGHT:
		current_shader = m_light_shader.get();
		break;
	case RenderMode::TEXTURED:
		current_shader = m_textured_shader.get();
		break;
	case RenderMode::WIREFRAME:
		current_shader = m_textured_shader.get();
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		break;
	default: break;
	}

	glm::mat4 view = cam.get_view();
	glm::mat4 mvp = m_projection_matrix * view;

	current_shader->bind();
	current_shader->set_mat4("u_mvp", glm::value_ptr(mvp));

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// render all the geometry
	glm::mat4 model;
	for (auto &mesh: m_meshes)
	{
		if (!mesh->m_cull) 
			glDisable(GL_CULL_FACE);
		else
			glEnable(GL_CULL_FACE);

		glBindVertexArray(mesh->m_vao);
		glDrawArrays(GL_TRIANGLES, 0, mesh->m_vertices.size());
	}
}

void Renderer::submit(std::shared_ptr<Mesh> mesh)
{
	m_meshes.push_back(mesh);
}
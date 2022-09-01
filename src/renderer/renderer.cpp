#include "renderer.hpp"

#include <glm/ext.hpp>
#include "GL/glew.h"
#include "gldebug.hpp"

Renderer::Renderer():
	m_light_shader("res/shaders/light.vs", "res/shaders/light.fs"),
	m_textured_shader("res/shaders/texture.vs", "res/shaders/texture.fs")
{}

Renderer::~Renderer()
{

}

void Renderer::on_resize(int width, int height)
{
	glViewport(0, 0, width, height);
	m_projection_matrix = glm::perspective( glm::radians(90.0f), (float)width / (float)height, 0.01f, 100.0f );
}

void Renderer::begin_scene()
{
	m_meshes.clear();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
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
		current_shader = &m_light_shader;
		break;
	case RenderMode::TEXTURED:
		current_shader = &m_textured_shader;
		break;
	case RenderMode::WIREFRAME:
		current_shader = &m_textured_shader;
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		break;
	default: break;
	}

	// render all the geometry
	glm::mat4 model;
	for (auto &mesh: m_meshes)
	{
		if (!mesh->m_cull) 
			glDisable(GL_CULL_FACE);

		glBindVertexArray(mesh->m_vao);
		glBindBuffer(GL_ARRAY_BUFFER, mesh->m_vbo);

		glDrawArrays(GL_TRIANGLES, 0, mesh->m_vertices.size());
	}

	log_gl_errors();
}

void Renderer::submit(std::shared_ptr<Mesh> mesh)
{
	m_meshes.push_back(mesh);
}
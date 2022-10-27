#pragma once

#include <GL/glew.h>
#include <wx/wx.h>
#include <wx/glcanvas.h>

#include "renderer/renderer.hpp"
#include "renderer/mesh.hpp"

class Canvas: public wxGLCanvas
{
public:
	Canvas( wxFrame *parent, wxGLAttributes &attrs );
	~Canvas();
	
	bool InitOpenGL();

	void OnMouseMove( wxMouseEvent &e );
	void OnRezise( wxSizeEvent &e );
	void OnTimer( wxTimerEvent &e );
	void OnPaint( wxPaintEvent &e );
	void Render();

private:
	bool m_initialized {false};
	wxFrame *m_parent;
	wxGLContext *m_context;
	Renderer m_renderer;
	Camera m_camera;
	std::shared_ptr<Mesh> m_cube;
	wxTimer m_timer;

	DECLARE_EVENT_TABLE()

};
#pragma once

#include <GL/glew.h>
#include <wx/wx.h>
#include <wx/glcanvas.h>

class Canvas: public wxGLCanvas
{
public:
	Canvas( wxFrame *parent, wxGLAttributes &attrs );
	~Canvas();
	
	bool InitOpenGL();

	void OnMouse( wxMouseEvent &e );
	void OnRezise( wxSizeEvent &e );
	void Render( wxPaintEvent &e );

private:
	bool m_initialized {false};
	wxFrame *m_parent;
	wxGLContext *m_context;

	DECLARE_EVENT_TABLE()

};
#include "canvas.hpp"
#include "core/logger.hpp"
#include "window_ids.hpp"

BEGIN_EVENT_TABLE( Canvas, wxGLCanvas )
	EVT_PAINT(Canvas::OnPaint)
	EVT_SIZE(Canvas::OnRezise)
	EVT_MOTION(Canvas::OnMouseMove)
	EVT_TIMER(ID_TIMER, Canvas::OnTimer)
END_EVENT_TABLE();

Canvas::Canvas( wxFrame *parent, wxGLAttributes &attrs ):
	wxGLCanvas(parent, attrs, wxID_ANY),
	m_timer(this, ID_TIMER)
{
	m_parent = parent;
	m_timer.Start(16);

	// Création du contexte pour OpenGL
	wxGLContextAttrs context_attribs;
	context_attribs
		.PlatformDefaults()
		.CoreProfile()
		.OGLVersion(3, 3)
		.EndList();

	m_context = new wxGLContext(this);

	Center();
}

Canvas::~Canvas()
{
	if( m_context != nullptr )
		delete m_context;
}

// évènements
void Canvas::OnRezise( wxSizeEvent &e )
{
	// si la fenêtre n'est pas affichée alors on fait rien
	if( !IsShownOnScreen() ) return;

	if( !m_initialized ) InitOpenGL();

	m_renderer.on_resize(e.m_size.x, e.m_size.y);
}

void Canvas::OnMouseMove( wxMouseEvent &e )
{
	static wxPoint last_position = e.GetPosition();
	wxPoint pos = e.GetPosition();

	if( wxGetMouseState().LeftIsDown() )
	{
		wxPoint delta = wxPoint( pos.x - last_position.x, pos.y - last_position.y);

		float dx = (float)delta.x / 100.0f;
		float dy = (float)delta.y / 100.0f;
		m_camera.rotate(dx, dy);
	}

	last_position = pos;

}

void Canvas::OnTimer( wxTimerEvent &e )
{
	Render();
}

void Canvas::OnPaint( wxPaintEvent &e )
{
	Render();
}

// rendu
bool Canvas::InitOpenGL()
{
	m_initialized = true;

	if( !m_context )
	{
		SD_ERROR("Aucun contexte OpenGL");
		return false;
	}

	if( !m_context->IsOK() )
	{
		SD_ERROR("Contexte OpenGL invalide");
		return false;
	}
	
	SetCurrent( *m_context );
	GLenum res = glewInit();
	if( res != GLEW_OK && res != GLEW_ERROR_NO_GLX_DISPLAY )
	{
		SD_ERROR("Impossible d'initialiser GLEW");
		return false;
	}

	glClearColor( 1.0f, 1.0f, 1.0f, 1.0f);
	
	if (!m_renderer.init())
	{
		SD_ERROR("Impossible d'initialiser le moteur de rendu");
		return false;
	}

	m_cube = std::make_shared<Mesh>(create_cube());
	return true;
}

void Canvas::Render()
{
	SetCurrent(*m_context);

	m_renderer.begin_scene();
	m_renderer.submit( m_cube );
	m_renderer.end_scene(m_camera, RenderMode::TEXTURED);

	SwapBuffers();
}
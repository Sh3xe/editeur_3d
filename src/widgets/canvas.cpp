#include "canvas.hpp"
#include "core/logger.hpp"

BEGIN_EVENT_TABLE( Canvas, wxGLCanvas )
	EVT_PAINT(Canvas::Render)
	EVT_SIZE(Canvas::OnRezise)
	EVT_MOUSE_EVENTS(Canvas::OnMouse)
END_EVENT_TABLE();

Canvas::Canvas( wxFrame *parent, wxGLAttributes &attrs ):
	wxGLCanvas(parent, attrs, wxID_ANY)
{
	m_parent = parent;

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
}

void Canvas::OnMouse( wxMouseEvent &e )
{

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
	
	return true;
}

void Canvas::Render( wxPaintEvent &e )
{
	SetCurrent(*m_context);
	glClear( GL_COLOR_BUFFER_BIT );

	

	SwapBuffers();
}
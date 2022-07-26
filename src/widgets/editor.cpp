#include "editor.hpp"
#include "../cmake_defines.hpp"
#include "window_ids.hpp"

#include <wx/aboutdlg.h>

BEGIN_EVENT_TABLE(Editor, wxFrame)
	EVT_MENU(ID_NEW, Editor::OnNew)
	EVT_MENU(ID_OPEN, Editor::OnOpen)
	EVT_MENU(ID_SAVE, Editor::OnSave)
	EVT_MENU(ID_SAVE_AS, Editor::OnSaveAs)
	EVT_MENU(ID_EXIT, Editor::OnExit)
	EVT_MENU(ID_ABOUT, Editor::OnAbout)
	EVT_MENU(ID_TEXTURED, Editor::OnTextured)
	EVT_MENU(ID_WIREFRAME, Editor::OnWireframe)
	EVT_MENU(ID_SOLID, Editor::OnSolid)
END_EVENT_TABLE();


Editor::Editor():
	wxFrame( nullptr, wxID_ANY, wxT("Éditeur ECO+"), wxDefaultPosition, wxSize(1280, 720))
{
	// icon
	wxIcon icon = wxIcon("res/images/icon.png");
	if( icon.IsOk() )
		SetIcon(icon);

	// gl attributes
	wxGLAttributes canvas_attributes;
	canvas_attributes
		.PlatformDefaults()
		.EndList();
/*.MinRGBA(8, 8, 8, 8)
		.DoubleBuffer()*/

	// allocate components
	m_toolbar = new ToolBar( this );
	m_canvas = new Canvas( this, canvas_attributes );
	m_scene_panel = new ScenePanel( this );

	// toolbar
	SetToolBar( m_toolbar );

	// resize components
	wxBoxSizer *s = new wxBoxSizer( wxHORIZONTAL );

	s->Add( m_canvas, 1, wxEXPAND | wxALL, 10 );
	s->Add( m_scene_panel, 0, wxEXPAND | wxUP | wxDOWN, 0 );

	SetSizer(s);

	// menu bar
	m_menu_bar = new wxMenuBar;

	wxMenu *file_menu = new wxMenu();
	wxMenu *view_menu = new wxMenu();
	wxMenu *help_menu = new wxMenu();

	// file menu
	file_menu->Append( ID_NEW, wxT("Nouvelle scène"), wxT("Créer une scène vide.") );
	file_menu->Append( ID_OPEN, wxT("Ouvrir.."), wxT("Ouvrir une scène.") );
	file_menu->Append( ID_SAVE, wxT("Sauvegarder"), wxT("Sauvegarder la scène courante.") );
	file_menu->Append( ID_SAVE, wxT("Sauvegarder sous.."), wxT("Sauvegarder la scène courante.") );
	file_menu->AppendSeparator();
	file_menu->Append( ID_EXIT, wxT("Quitter"), wxT("Quitter le logiciel") );

	// view menu
	view_menu->AppendRadioItem(ID_SOLID, wxT("Vue solide"));
	view_menu->AppendRadioItem(ID_WIREFRAME, wxT("Vue «fil de fer»"));
	view_menu->AppendRadioItem(ID_TEXTURED, wxT("Vue texturé"));

	// help menu
	help_menu->Append(ID_TUTORIAL, wxT("Utilisation"));
	help_menu->Append(ID_ABOUT, wxT("À propos"));

	m_menu_bar->Append(file_menu, wxT("Fichier"));
	m_menu_bar->Append(view_menu, wxT("Vue"));
	m_menu_bar->Append(help_menu, wxT("Aide"));

	SetMenuBar(m_menu_bar);
}

void Editor::OnNew( wxCommandEvent &e )
{

}

void Editor::OnExit( wxCommandEvent &e )
{
	Close(true);
}

void Editor::OnSave( wxCommandEvent &e )
{

}

void Editor::OnSaveAs( wxCommandEvent &e )
{

}

void Editor::OnAbout( wxCommandEvent &e )
{
	// à refaire.
	wxAboutDialogInfo infos;
	infos.AddDeveloper( wxT("Arnaud PELISSIER") );
	infos.SetVersion( "0.0.0", "Alpha 0.0.0" );
	infos.SetName( wxT("Éditeur ECO+") );

	wxIcon icon = wxIcon("res/images/icon.png");
	if( icon.IsOk() )
		infos.SetIcon( icon );

	wxAboutBox(infos, this);
}

void Editor::OnTutorial( wxCommandEvent &e )
{

}

void Editor::OnOpen( wxCommandEvent &e )
{

}

void Editor::OnViewChange( wxCommandEvent &e )
{

}

void Editor::OnTextured( wxCommandEvent &e )
{

}

void Editor::OnWireframe( wxCommandEvent &e )
{

}

void Editor::OnSolid( wxCommandEvent &e )
{

}

#pragma once

#include "tool_bar.hpp"
#include "scene_panel.hpp"
#include "canvas.hpp"

class Editor: public wxFrame
{
public:
	Editor();

	// events callbacks
	void OnNew( wxCommandEvent &e );
	void OnOpen( wxCommandEvent &e );
	void OnExit( wxCommandEvent &e );
	void OnSave( wxCommandEvent &e );
	void OnSaveAs( wxCommandEvent &e );
	void OnAbout( wxCommandEvent &e );
	void OnTutorial( wxCommandEvent &e );
	void OnViewChange( wxCommandEvent &e );
	void OnTextured( wxCommandEvent &e );
	void OnWireframe( wxCommandEvent &e );
	void OnSolid( wxCommandEvent &e );


public:
	Tools m_selected_tool { Tools::select };

private:
	ToolBar *m_toolbar;
	ScenePanel *m_scene_panel;
	Canvas *m_canvas;
	wxMenuBar *m_menu_bar;

	DECLARE_EVENT_TABLE()

};
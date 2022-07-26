#pragma once

#include <wx/wx.h>

class ScenePanel: public wxPanel
{
public:
	ScenePanel( wxFrame *parent );

private:
	wxFrame *m_parent;
	wxListBox *m_list_box;
};
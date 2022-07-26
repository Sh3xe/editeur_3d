#include "scene_panel.hpp"

ScenePanel::ScenePanel( wxFrame *parent ):
	wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, wxT("Scène"))
{
	m_parent = parent;
	m_list_box = new wxListBox(this, wxID_ANY, wxDefaultPosition, wxSize(200, 400), wxArrayString(), wxLB_NEEDED_SB | wxLB_SINGLE);
}

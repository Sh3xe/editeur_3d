#include "tool_bar.hpp"

ToolBar::ToolBar( wxFrame *parent ):
	wxToolBar( parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTB_VERTICAL )
{
	wxBitmap icon_select = wxBitmap( wxT("res/images/select.png") );
	wxBitmap icon_rotate = wxBitmap( wxT("res/images/rotate.png") );
	wxBitmap icon_scale = wxBitmap( wxT("res/images/scale.png") );
	wxBitmap icon_move = wxBitmap( wxT("res/images/move.png") );

	AddRadioTool(1, wxT("Selection"), icon_select);
	AddRadioTool(1, wxT("Tourner"), icon_rotate);
	AddRadioTool(1, wxT("Dilater"), icon_scale);
	AddRadioTool(1, wxT("Déplacer"), icon_move);
}
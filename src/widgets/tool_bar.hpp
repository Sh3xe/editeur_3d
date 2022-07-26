#pragma once

#include <wx/wx.h>

enum class Tools
{
	select,
	scale,
	rotate,
	move
};

class ToolBar: public wxToolBar
{
public:
	ToolBar( wxFrame *parent );
};
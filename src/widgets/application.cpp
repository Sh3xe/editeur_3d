#include "application.hpp"
#include "editor.hpp"
#include "cmake_defines.hpp"

IMPLEMENT_APP( Application );

bool Application::OnInit()
{
	wxSetWorkingDirectory( ROOT_DIR );
	Editor *editor = new Editor;
	editor->Show(true);

	return true;
}
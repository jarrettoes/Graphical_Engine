#include "Window.h"
#include "GE_Core/src/CoreBuild.h"

void GE_EDITOR::window::init_window()
{
	wcscpy(win_class_name, L"GE_Editor");

	WNDCLASSW win_class;
	win_class.lpszClassName =									win_class_name;
	win_class.hInstance =										m_windowInstance;
	win_class.lpfnWndProc =										windowProc;

	RegisterClassW(&win_class);

	m_windowHandle = CreateWindowW(win_class_name, "Grpahical Engine", WS_OVERLAPPEDWINDOW, 
									CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, );

}

void GE_EDITOR::window::destroy_window()
{
}

GE_EDITOR::window::~window()
{
	destroy_window();
}

LRESULT GE_EDITOR::windowProc(HWND p1, UINT u1, WPARAM w1, LPARAM l1)
{
	return LRESULT();
}

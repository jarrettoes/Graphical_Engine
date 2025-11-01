/***********************************************************************************************************
*	  ____   _____
*	 / ___| | ____|
*	| |  _  |  _|
*	| |_| | | |___
*	 \____| |_____|
* __________________________________________________________________________________________________________
*
* FILE TITLE:
*
* FILE AUTOHOR:
*
* FILE PURPOSE:
*
************************************************************************************************************/

#include "window.h"
#include "GL_init.h"
#include "imgui_test.h"
#include "GE_CoreUtilites.h"

int GE_EDITOR::window::init_window()
{
	auto m_gl_ptr = GE_GRAPHICS::gl_init::gl_init_instance();
	auto m_gui_ptr = GE_ENGINE_CORE::imgui_engine::imgui_instance();

	if ( m_gl_ptr == NULL)
	{
		__GE_ENGINE_ERROR_LOG("m_gl_unique_ptr is null!");
		return -1;
	}

	__GE_ENGINE_SUCESS_LOG("m_gl_unique_ptr is initalized!");

	if (m_gui_ptr == NULL)
	{
		__GE_ENGINE_ERROR_LOG("m_gui_ptr is null!");
		return -1;
	}
	
	__GE_ENGINE_SUCESS_LOG("m_gui_ptr is initalized!");

	const wchar_t WIN_CLASSNAME[] = L"Graphical Engine";

	WNDCLASSEXW winclass{};
	winclass.cbSize = sizeof(WNDCLASSEX);
	winclass.lpszClassName = WIN_CLASSNAME;
	winclass.hInstance = m_windowInstance;
	winclass.lpfnWndProc = window_proc;

	//we must register the window class
	RegisterClassExW(&winclass);

	m_windowHandle = CreateWindowExW(0, WIN_CLASSNAME, L"GE", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, m_windowInstance, NULL);

	if (m_windowHandle == NULL)
	{
		__GE_ENGINE_ERROR_LOG("m_windowHandle is null!");
		return EXIT_FAILURE;
	}

	m_gl_ptr.get()->init_window(m_windowHandle);
	m_gui_ptr.get()->imgui_init(m_windowHandle);
	ShowWindow(m_windowHandle, SW_SHOW);

	__GE_ENGINE_SUCESS_LOG("HELLO WINDOW!");

	return EXIT_SUCCESS;
}

GE_EDITOR::window::~window()
{
	DestroyWindow(m_windowHandle);
}



LRESULT GE_EDITOR::window_proc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	LRESULT gui_result = GE_ENGINE_CORE::imgui_proc_handle_wrapper(hwnd, uMsg, wParam, lParam);
	if(gui_result != 0)
		return gui_result;

	switch(uMsg)
	{
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
	}

	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

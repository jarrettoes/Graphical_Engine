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


int GE_EDITOR::window::init_window()
{
	const wchar_t WIN_CLASSNAME[] = L"Graphical Engine";

	WNDCLASSEXW winclass{};
	winclass.cbSize = sizeof(WNDCLASSEX);
	winclass.lpszClassName = WIN_CLASSNAME;
	winclass.hInstance = m_windowInstance;
	winclass.lpfnWndProc = window_proc;

	RegisterClassExW(&winclass);
	

	m_windowHandle = CreateWindowExW(0, WIN_CLASSNAME, L"GE", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, m_windowInstance, NULL);

	if (m_windowHandle == NULL)
	{
		return EXIT_FAILURE;
	}

	ShowWindow(m_windowHandle, SW_SHOW);

	return EXIT_SUCCESS;
}

GE_EDITOR::window::~window()
{
	DestroyWindow(m_windowHandle);
}

LRESULT GE_EDITOR::window_proc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
		case WM_DESTROY:
			PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

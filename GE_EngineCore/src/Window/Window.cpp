#include "Window.h"


bool GE_EngineCore::Window::initalize()
{

	WNDCLASSEXW win_class = {}; 
	
	win_class.hInstance = m_instance;
	win_class.cbSize = sizeof(WNDCLASSEX);
	win_class.lpszClassName = m_class_name;
	win_class.lpfnWndProc = win_proc;
	auto win_class_ID = RegisterClassExW(&win_class);

	if(!win_class_ID)
		throw std::runtime_error("the win_class_ID failed!"); 
	
	// used teh MAKEINATOM marco to save some memory from the wide char
	m_windowHandle = CreateWindowExW(WS_OVERLAPPEDWINDOW, MAKEINTATOM(win_class_ID), L"main window", WS_OVERLAPPED, 
									CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT ,nullptr, nullptr,
									m_instance, nullptr);

	if(m_windowHandle == nullptr) return false; 

	ShowWindow(m_windowHandle, SW_SHOW);

	return true;
}

void GE_EngineCore::Window::shutdown()
{
	DestroyWindow(m_windowHandle);
}

GE_EngineCore::Window::~Window()
{
	shutdown(); 
}

LRESULT GE_EngineCore::win_proc(HWND p_HWND, UINT p_msg, WPARAM p_WPARAM, LPARAM L_PARAM)
{

	switch (p_msg)
	{
		case WM_CLOSE:
			 PostQuitMessage(0);
			 break;

		case WM_DESTROY:
			 return 1;
	}

	return DefWindowProcW(p_HWND, p_msg, p_WPARAM, L_PARAM); 
}

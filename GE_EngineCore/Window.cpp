#include "Window.h"


bool GE_EngineCore::Window::initalize()
{

	WNDCLASSEXW win_class = {}; 
	
	win_class.hInstance = m_instance;
	win_class.cbSize = sizeof(WNDCLASSEX);
	win_class.lpszClassName = m_class_name;
	win_class.lpfnWndProc = win_proc;
	
	RegisterClassExW(&win_class); 

	win_rectanlge win_rect;
	RECT rect_dim; 
	win_rect.height = 1920;
	win_rect.width = 1080; 
	win_rect.x = rect_dim.right;
	win_rect.y = rect_dim.left;

	// used teh MAKEINATOM marco to save some memory from the wide char
	m_windowHandle = CreateWindowExW(WS_OVERLAPPEDWINDOW, MAKEINTATOM(m_class_name), L"main window", WS_OVERLAPPED, 
									win_rect.x, win_rect.y, win_rect.width, win_rect.height ,nullptr, nullptr,
									m_instance, nullptr);

	if(m_windowHandle == nullptr) return; 

	ShowWindow(m_windowHandle, SW_SHOW);

	return true;
}

void GE_EngineCore::Window::shutdown()
{
	DestroyWindow(m_windowHandle);
}

void GE_EngineCore::Window::post_messages()
{
	MSG m_windowMsg;
	while (GetMessage(&m_windowMsg, m_windowHandle, 0, 0) > 0)
	{
		TranslateMessage(&m_windowMsg);
		DispatchMessageW(&m_windowMsg);
	}
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

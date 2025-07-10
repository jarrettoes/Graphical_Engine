#include "window.hpp"

window::Window::Window()
{
	className = L"Graphical Engine";
	
	WNDCLASS win = {};
	win.lpszClassName = className;
	win.lpfnWndProc = windowProc;
	win.hInstance = m_instance;

	RegisterClass(&win);
	

	m_windowHandle = CreateWindowEx(0, className, L"main windodw", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
									CW_USEDEFAULT, CW_USEDEFAULT, nullptr, nullptr, m_instance, nullptr);

	if(m_windowHandle == nullptr) return;

	ShowWindow(m_windowHandle, SW_SHOW);

	MSG msg = {};
	while (GetMessage(&msg, nullptr, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}

	window::Window::~Window()
	{
		DestroyWindow(m_windowHandle);
	}


LRESULT window::windowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
		case WM_CLOSE:
			DestroyWindow(hwnd);
			break;
		case WM_DESTROY:
			PostQuitMessage(1);
			return 0;
		
	}
	return DefWindowProc(hwnd, msg, wParam, lParam);
}

#include <Private/Window.h>
#include "Private/Logger.h"

bool GE_EngineCore::Window::initalize()
{

	WNDCLASSEXW win_class = {};

	win_class.hInstance = m_instance;
	win_class.cbSize = sizeof(WNDCLASSEX);
	win_class.lpszClassName = m_class_name;
	win_class.lpfnWndProc = win_proc;
	auto win_class_ID = RegisterClassExW(&win_class);

	if (!win_class_ID)
	{
		throw std::runtime_error("the win_class_ID failed!");
		MessageBoxW(nullptr, L"Failed to regiter window class", L"Error", MB_OK);
		return false;
	}

	error_result = E_INVALIDARG;

	// used teh MAKEINATOM marco to save some memory from the wide char
	m_windowHandle = CreateWindowExW(0, MAKEINTATOM(win_class_ID), L"main window", WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, nullptr, nullptr,
		m_instance, nullptr);

	
	if (m_windowHandle == nullptr)
	{
		Logger::error_popup(error_result,"failed to create a window!");
		return false;
	}

	ShowWindow(m_windowHandle, SW_SHOW);
	UpdateWindow(m_windowHandle);

	DX = std::make_unique<GE_Graphics::DirectXDevices>(); 

	DX.get()->Init3D_Device(m_windowHandle); 

	return true;
}

GE_EngineCore::Window::~Window()
{
	DestroyWindow(m_windowHandle);
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

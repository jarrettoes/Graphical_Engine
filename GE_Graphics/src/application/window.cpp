#include "window.hpp"

namespace window
{
	Window::Window()
	{
<<<<<<< HEAD
		const wchar_t* class_name = L"GE WINDOW";

		WNDCLASS win = {};
		win.hCursor = LoadCursor(nullptr, IDC_ARROW);
		win.hIcon = LoadIcon(nullptr, IDC_ICON);
		win.hInstance = m_instance;
		win.lpszClassName = class_name;
		win.lpfnWndProc = windowProc;

		RegisterClass(&win); 
		m_windowHandle = CreateWindow(class_name, L"main window", WS_OVERLAPPEDWINDOW, 
									  CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
									   nullptr, nullptr, m_instance, nullptr);

		if(m_windowHandle == NULL) return;

		ShowWindow(m_windowHandle, SW_SHOW); 
	
		MSG m_msg = {};
		while (GetMessage(&m_msg, m_windowHandle, 0, 0) > 0)
		{
			TranslateMessage(&m_msg);
			DispatchMessage(&m_msg);
=======
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
>>>>>>> 090b10db32247e218a1cc659d024d71e5f94f07e
		}
	}

	Window::~Window()
	{
<<<<<<< HEAD
		DestroyWindow(m_windowHandle);
	}

=======
		UnregisterClass(className, m_instance);
	}


>>>>>>> 090b10db32247e218a1cc659d024d71e5f94f07e
	LRESULT windowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		switch (msg)
		{
			case WM_CLOSE:
<<<<<<< HEAD
				 std::cout << "Good bye" << std::endl;
				 break; 
	
			case WM_DESTROY:
				 PostQuitMessage(0);
				 return 0;
		}
	
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}
=======
				DestroyWindow(hwnd);
				break;
			case WM_DESTROY:
				PostQuitMessage(1);
				return 0;
		
		}
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}

>>>>>>> 090b10db32247e218a1cc659d024d71e5f94f07e
}

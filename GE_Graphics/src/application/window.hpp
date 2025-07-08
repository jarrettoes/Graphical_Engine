#pragma once

#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <iostream>
#include <Windows.h>



struct window_size
{
	int s_width;
	int s_height;
};
 
namespace window
{
	LRESULT CALLBACK windowProc (HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

	class Window
	{

	public:

		Window();
		Window(const Window&) = delete;	
		Window& operator=(const Window&) = delete;
		~Window();  

	private:

		HWND m_windowHandle;
		HINSTANCE m_instance;
		const wchar_t* className;

	};
}


#endif // !WINDOW_HPP

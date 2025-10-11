/***********************************************
* 
* Graphical Engine
* 
* window.h: windows api for creating the main window
* 
************************************************/

#pragma once

#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include <Windows.h>

namespace GE_EDITOR
{
	class window
	{
		public:
			window() = default;
			~window();
			
			int init_window();

		private:

			HWND m_windowHandle;
			HINSTANCE m_windowInstance;
	};

	LRESULT CALLBACK window_proc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
}

#endif

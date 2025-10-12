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

			//constructors
			window() = default;
			~window();
			
			//a simple window init function. 
			int init_window();

			//we need a getter for the window handle so we can connect it to our main window
			HWND handle_getter() {return m_windowHandle;} //shoud do it

		private:

			HWND m_windowHandle;
			HINSTANCE m_windowInstance;
	};

	LRESULT CALLBACK window_proc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
}

#endif

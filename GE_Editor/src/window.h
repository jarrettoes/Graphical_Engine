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
#include <memory>

	
namespace GE_EDITOR
{
	LRESULT CALLBACK window_proc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	class window
	{
		public:

			//constructors
			window() = default;
			~window();
			
			//a simple window init function. 
			int init_window();
			//getter for the window handle;
			HWND get_windowHandle() {return m_windowHandle;}

		private:

			HWND m_windowHandle;
			HINSTANCE m_windowInstance;
			
		
	};

}

#endif

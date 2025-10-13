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
#include <GL_init.h>
#include <memory>

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

		private:

			HWND m_windowHandle;
			HINSTANCE m_windowInstance;
		
	};

	LRESULT CALLBACK window_proc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
}

#endif

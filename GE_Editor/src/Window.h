/********************************************************
*	  ____   _____
*	 / ___| | ____|
*	| |  _  |  _|
*	| |_| | | |___
*	 \____| |_____|
* _______________________________________________________
*
* FILE TITLE: Logger.h
*
* FILE AUTOHOR: Jarrett Williams
*
* FILE PURPOSE: for logging functionality for the game enigne!
*
*********************************************************/

#pragma once

#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include <Windows.h>

namespace GE_EDITOR
{
	LRESULT windowProc(HWND p1, UINT u1, WPARAM w1, LPARAM l1);
	class window
	{
		public:

			window() = default;
			window(const window&) = delete;
			void operator = (const window&) = delete;
			
			window(const window&&) = delete;
			void operator = (const window&&) = delete;
			virtual ~window();

			void init_window();
			void destroy_window();


		private:

			HANDLE m_windowHandle;
			HINSTANCE m_windowInstance;
			wchar_t win_class_name[];
		
	};
}

#endif
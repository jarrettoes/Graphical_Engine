
/********************************************************
*	  ____   _____
*	 / ___| | ____|
*	| |  _  |  _|
*	| |_| | | |___
*	 \____| |_____|
* _______________________________________________________
*
* FILE TITLE: Window.h, Window.cpp
*
* FILE AUTOHOR: Jarrett Williams
*
* FILE PURPOSE: To create a window application using Microsoft Window API
*
*********************************************************/

#pragma once

#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include <Windows.h>
#include "BaseEngineCore.h"

namespace GE_EngineCore
{	struct win_rectanlge
	{
		int x; 
		int y;
		int width;
		int height;
	
		win_rectanlge(int p_width = 0, int p_height = 0, int p_x = 0, int p_y = 0) : 
					  width(p_width), height(p_height), x(p_x), y(p_y) {}; 
	};

	LRESULT CALLBACK win_proc(HWND p_HWND,
							  UINT p_msg,
							  WPARAM p_WPARAM,
							  LPARAM L_PARAM);

	class Window : public BaseEngineCore
	{
		public:
	
			//default constructor
			Window() = default;
			
			//copy class functions
			Window(const Window&) = delete;
			void operator = (const Window&) = delete;

			virtual bool initalize() override;
			virtual void shutdown() override;

			void post_messages();
			
			// moveable class functions
			Window(const Window&&) = delete;
			void operator = (const Window&&) = delete;
			virtual ~Window();

		private:

			HINSTANCE m_instance; 
			HWND m_windowHandle; 
			const wchar_t* m_class_name = L"Graphical Enigne";
	};
}

#endif


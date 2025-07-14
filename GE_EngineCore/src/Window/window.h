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

#include "include/GE_EngineCoreAPI.h"
#include <iostream>
#include <Windows.h>

namespace GE_EngineCore
{
	LRESULT CALLBACK win_proc(HWND p_HWND,
		UINT p_msg,
		WPARAM p_WPARAM,
		LPARAM L_PARAM);

	class GE_ENGINECORE_API Window
	{
	public:

		//default constructor
		Window() = default;

		//copy class functions
		Window(const Window&) = delete;
		void operator = (const Window&) = delete;

		bool initalize();

		// moveable class functions
		Window(const Window&&) = delete;
		void operator = (const Window&&) = delete;
		virtual ~Window();

		HWND get_windowHandle() { return m_windowHandle; }

	private:

		HINSTANCE m_instance;
		HWND m_windowHandle;
		const wchar_t* m_class_name = L"Graphical Enigne";
	};
}

#endif


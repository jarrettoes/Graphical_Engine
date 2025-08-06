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

#include "Private/GE_EngineCoreAPI.h"
#include "Private/DirectX_Devices.h"
#include <iostream>
#include <Windows.h>
#include <memory>

namespace GE_EngineCore
{
	LRESULT CALLBACK win_proc(HWND p_HWND,
							  UINT p_msg,
							  WPARAM p_WPARAM,
							  LPARAM L_PARAM);

	class GE_ENGINECORE_API Window
	{
	public:

//**********************************************************************************************************************************************
// public: For the window class just have a constructor, copy constructor, and copy operator, the rules of 5 functions really. and we have a 
// simple getter to get the window handle.
//**********************************************************************************************************************************************

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

//***********************************************************************************************************************************************
// private: some variables for the window class.
//***********************************************************************************************************************************************

		HINSTANCE m_instance;
		HWND m_windowHandle;
		const wchar_t* m_class_name = L"Graphical Enigne";
		HRESULT warning_result, error_result;

		std::unique_ptr<GE_Graphics::DirectXDevices> DX; 
	};
}

#endif


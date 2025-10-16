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
#include <imgui.h>
#include <imgui_impl_win32.h>

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	
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

			//for imgui
			int imgui_init();
			int imgui_render_start();
			int imgui_render_end();
			int imgui_shutdown();

			//getter for the window handle;
			HWND get_windowHandle() {return m_windowHandle;}

		private:

			HWND m_windowHandle;
			HINSTANCE m_windowInstance;
		
	};

	LRESULT CALLBACK window_proc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

}

#endif

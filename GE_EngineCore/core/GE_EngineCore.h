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

#include <Windows.h>

#ifndef GE_ENGINE_CORE_EXPORTS
	#define GE_ENGINE_CORE_API __declspec(dllexport)
#else
	#define GE_ENGINE_CORE_API __declspec(dllimport)
#endif

namespace GE_ENGINE_CORE
{
	//call this for the window proc function if using windows API
	GE_ENGINE_CORE_API LRESULT imgui_proc_handle_wrapper(HWND _hwnd, UINT _uint, WPARAM _wparam, LPARAM _lparam);
}

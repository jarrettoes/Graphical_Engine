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

#ifndef IMGUI_INIT
#define IMGUI_INIT

#include <iostream>
#include <GE_CoreUtilites.h>
#include <Windows.h>

namespace GE_EDITOR
{
	class imGui_init
	{
		public:
	
			//constructors
			imGui_init() = default;
			imGui_init(const imGui_init&) = delete;
			imGui_init operator = (const imGui_init&) = delete;
			~imGui_init();


			//an initalizer for imGui. we'll need a window handle for this
			void init(HWND hwnd);
			
			//place this at the start of the loop
			void imGui_update_start();
			//place this at the end of the loop
			void imGui_uddate_end();
			
			//place at the end
			void imGui_shutdown();

			static std::shared_ptr<imGui_init> imGui_instance()
			{
				static std::shared_ptr<imGui_init> imGui_sigeleton = std::make_shared<imGui_init>();
				return imGui_sigeleton;
			}
			
	};
}

#endif


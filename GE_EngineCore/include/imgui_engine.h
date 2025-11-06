/***********************************************************************************************************
*	  ____   _____
*	 / ___| | ____|
*	| |  _  |  _|
*	| |_| | | |___
*	 \____| |_____|
* __________________________________________________________________________________________________________
*
* 
*
* 
*
*
*
************************************************************************************************************/

#pragma once

#ifndef IMGUI_TEST_H
#define IMGUI_TEST_H

#include "GE_EngineCore.h"
#include <iostream>
#include <Windows.h>
#include <memory>

namespace GE_ENGINE_CORE
{
	class GE_ENGINE_CORE_API imgui_engine
	{
		public:
		
			//this class dont really need any constructors or deconstructors I think. 
			//this class is only used for initalizng/handling imgui as for EngineCore Utilites	


			//call "imgui_init" at before the loop
			void imgui_init(HWND hwnd);
			//call "imgui_start" at the start of the loop
			void imgui_start();
			//call "imgui_end" at the end of the loop
			void imgui_end();
			//call "imgui_clean" within a deconstructor
			void imgui_clean();
			
			//========================================================
			// some helpfull getters for shared pointers of this class	
			//========================================================
			static std::shared_ptr<imgui_engine> imgui_instance()
			{
				static std::shared_ptr<imgui_engine> imgui_singleton = std::make_shared<imgui_engine>();
				return imgui_singleton;
			}
	};
}

#endif
/***********************************************************************************************************
*	  ____   _____
*	 / ___| | ____|
*	| |  _  |  _|
*	| |_| | | |___
*	 \____| |_____|
* __________________________________________________________________________________________________________
*
* FILE TITLE: GL_init.h
*
* FILE AUTOHOR: Jarrett Williams
*
* FILE PURPOSE: GL_init purpose is to initate openGL graphics to be displayed in the main window within GE_Editor
*
************************************************************************************************************/

#pragma once

#ifndef GL_INIT_H
#define GL_INIT_H

#include <GE_Graphics.h>
#include <iostream>
#include <Windows.h>

namespace GE_GRAPHICS
{
	class GE_GRAPHICS_API gl_init
	{
		public:

			gl_init() = default;
			gl_init(const gl_init&) = delete;
			gl_init& operator=(const gl_init&) = delete;                                                        
			~gl_init();

			int init_window(HWND hwnd);

			void gl_render();
			void gl_quit();

		//========================================================
		// some helpfull getters for shared pointers of this class	
		//========================================================
		static std::shared_ptr<gl_init> gl_init_instance()
		{
			static std::shared_ptr<gl_init> gl_init_sigeleton = std::make_shared<gl_init>();
			return gl_init_sigeleton;
		}
		

		private:

			HDC gl_hdc = nullptr;
			HGLRC openGl_context = nullptr;

	};
}

#endif

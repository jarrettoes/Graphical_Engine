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

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <Windows.h>

namespace GE_GRAPHICS
{
	class gl_init
	{
		public:
			
			//constructors
			gl_init();
			~gl_init();

			
			//this init funciton will initate getting the handle for opengl graphics
			void init(HWND hwnd);

		private:
	
	};
}

#endif

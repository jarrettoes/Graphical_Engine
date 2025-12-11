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

#ifndef APPLICATION_H
#define APPLICATION_H

#include <iostream>
#include <memory>
#include "window.h"
#include "GL_init.h"
#include "imgui_engine.h"
#include "SDL_engine.h"
#include <source_location>

namespace GE_EDITOR
{
	class application
	{
		public:

			application();
			~application();

			void run_app();
			void quit_app();

		private:

			bool m_loopInit;

			std::unique_ptr<window> window_ptr;	
			std::shared_ptr<GE_GRAPHICS::gl_init> gl_ptr;
			std::shared_ptr<GE_ENGINE_CORE::imgui_engine> imgui_ptr;
			std::shared_ptr<GE_ENGINE_CORE::SDL_engine> SDL_ptr;

	};
}

#endif

/********************************************************
*	  ____   _____
*	 / ___| | ____|
*	| |  _  |  _|
*	| |_| | | |___
*	 \____| |_____|
* _______________________________________________________
*
* FILE TITLE: 
*
* FILE AUTOHOR:
*
* FILE PURPOSE: 
*
*********************************************************/

#pragma once

#ifndef APPLICATION_H
#define APPLICATION_H

#include <memory>
#include <iostream>
#include <include/Window/window.h>

namespace GE_Editor
{
	class Application
	{
		public:
	
			Application();
			virtual ~Application();

			void run();
			void quit() {m_isRunning = false; }
		
		private:
			
			bool m_isRunning;
			std::unique_ptr<GE_EngineCore::Window> m_window; 

	};
}

#endif

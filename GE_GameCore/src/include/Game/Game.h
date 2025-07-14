
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

#ifndef GAME_H
#define GAME_H


#include <include/Window/Window.h>
#include <iostream>
#include <memory>

namespace GE_GameCore 
{
	class Game
	{
		public:
	
			Game();
			Game(const Game&) = delete;
			void operator = (const Game&) = delete;
			
			Game(const Game&&) = delete;
			void operator = (const Game&&) = delete;
			virtual ~Game();

			void run();
			void quit() {m_isRunning = false;}

		private:

			bool m_isRunning;
			std::unique_ptr<GE_EngineCore::Window> m_window; 
	};
}

#endif


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

#include <iostream>
#include "BaseGameCore.h"
#include <src/Window/Window.h>

namespace GE_GameCore 
{
	class Game : public BaseGameCore
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

		protected:
	


		private:

			bool m_isRunning;
			std::unique_ptr<GE_EngineCore::Window> main_window; 



	};
}

#endif

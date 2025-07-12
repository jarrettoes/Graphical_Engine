
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

		protected:
	


		private:


	};
}


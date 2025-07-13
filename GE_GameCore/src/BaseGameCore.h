
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

#include <iostream>
#include <src/BaseEngineCore.h>
#include <src/Window/Window.h>


namespace GE_GameCore
{
	class BaseGameCore : public  GE_EngineCore::BaseEngineCore
	{
		public:
	
			BaseGameCore() = default;
			virtual bool initalize() override = 0;
			virtual void update(float deltaTime) = 0; 
			virtual void shutdown() override = 0;
			virtual ~BaseGameCore() = default ;

		private:
	};
}


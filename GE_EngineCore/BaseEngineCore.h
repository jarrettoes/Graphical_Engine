
/********************************************************
*	  ____   _____
*	 / ___| | ____|
*	| |  _  |  _|
*	| |_| | | |___
*	 \____| |_____|
* _______________________________________________________
*
* FILE TITLE: BaseEngineCore
*
* FILE AUTOHOR: Jarrett Williams
*
* FILE PURPOSE: To have functions for any Core Engine functionaility
*
*********************************************************/

#pragma once

#ifndef BASEENGINECORE_H
#define BASEENGINECORE_H

#include <iostream>

namespace GE_EngineCore
{
	class BaseEngineCore
	{
		public:
	
			BaseEngineCore() = default;
			virtual bool initalize() = 0;
			virtual void update(float delta) = 0;
			virtual void shutdown() = 0;
			virtual ~BaseEngineCore() = default;

		protected:
	


		private:


	};
}

#endif
/********************************************************
*	  ____   _____
*	 / ___| | ____|
*	| |  _  |  _|
*	| |_| | | |___
*	 \____| |_____|
* _______________________________________________________
*
* FILE TITLE: Input.h
*
* FILE AUTOHOR: Jarrett Williams
*
* FILE PURPOSE: For keystrokes and controller input for the engine!
*
*********************************************************/

#pragma once

#ifndef INPUT_H
#define INPUT_H

#include "GE_EngineCoreAPI.h"

namespace GE_EngineCore {
	class GE_ENGINECORE_API Input
	{
		public:
//#############################################################################################################################
// public: 
//#############################################################################################################################
		
			Input();
			Input(const Input &) = delete;
			void operator=(const Input&) = delete;
			
			Input(const Input&&) = delete;
			void operator=(const Input&&) = delete;
			virtual ~Input();


		private:
//#############################################################################################################################
// private:
//#############################################################################################################################

			 

	};
}

#endif // !INPUT_H

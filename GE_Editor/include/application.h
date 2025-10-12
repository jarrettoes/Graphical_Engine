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
	};
}

#endif
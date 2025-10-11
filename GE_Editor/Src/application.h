/******************************************************************************************************
*
* Graphical Engine
*
* application.h: creating a application class for the main run funciton to execute the main game loop
*
******************************************************************************************************/

#pragma once

#ifndef APPLICATION_H
#define APPLICATION_H

#include <iostream>
#include <memory>
#include "window.h"

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
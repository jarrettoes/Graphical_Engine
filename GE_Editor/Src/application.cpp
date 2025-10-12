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

#include "application.h"
#include <Windows.h>
#include <GE_CoreUtilites.h>

GE_EDITOR::application::application()
{
	window_ptr = std::make_unique<window>();
	m_loopInit = true;

}

void GE_EDITOR::application::run_app()
{	
	if (window_ptr == nullptr)
	{
		std::cout << "window_ptr returned nullptr" << std::endl;
		quit_app();
		return;
	}

	window_ptr.get()->init_window();

	__GE_ENGINE_ERROR_LOG("this is the error");
	__GE_ENGINE_INFO_LOG("this is the info");
	__GE_ENGINE_WARN_LOG("this is the warning");

	MSG local_msg{};
	while (m_loopInit)
	{
		while (PeekMessage(&local_msg, NULL, 0, 0, PM_REMOVE) > 0)
		{
			if (local_msg.message == WM_QUIT)
				quit_app();

			TranslateMessage(&local_msg);
			DispatchMessage(&local_msg);
		}
	}
}

void GE_EDITOR::application::quit_app()
{
	std::cout << "good bye!" << std::endl;
	m_loopInit = false;
}

GE_EDITOR::application::~application()
{
	quit_app();
}
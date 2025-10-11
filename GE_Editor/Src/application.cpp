#include "application.h"
#include <Windows.h>

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

		std::cout << "the main loop is running" << std::endl;
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
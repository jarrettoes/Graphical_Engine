#include "Game.h"

GE_GameCore::Game::Game()
{
	m_isRunning = true;
	main_window = std::make_unique<GE_EngineCore::Window>();
 
}

GE_GameCore::Game::~Game()
{
	quit();
}

void GE_GameCore::Game::run()
{
	while (m_isRunning)
	{
		main_window.get()->initalize(); 
	
		MSG m_windowMsg;
		while (PeekMessage(&m_windowMsg, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&m_windowMsg);
			DispatchMessageW(&m_windowMsg);
		}
	}
	
}

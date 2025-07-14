#include <include/Game/Game.h>
#include <iostream>
#include <Windows.h>

GE_GameCore::Game::Game()
{
	m_window = std::make_unique<GE_EngineCore::Window>();
	m_isRunning = true; 
}

GE_GameCore::Game::~Game()
{
	quit(); 
}

void GE_GameCore::Game::run()
{
	if (!m_window->initalize())
	{
		MessageBoxW(nullptr, L"initalize() failed!", L"Init Error", MB_OK);
		return;
	}

	MSG win_msg = {}; 
	while (m_isRunning)
	{
		while (PeekMessageW(&win_msg, m_window.get()->get_windowHandle(), 0, 0, PM_REMOVE))
		{
			TranslateMessage(&win_msg); 
			DispatchMessageW(&win_msg);


			if (win_msg.message == WM_QUIT) m_isRunning = false;

		}
		Sleep(1);
	}
}

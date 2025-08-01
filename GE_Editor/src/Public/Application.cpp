#include "Private/Application.h"
#include "Private/window.h"
#include "Private/GE_EngineCoreMacros.h"

using namespace GE_EngineCore; 

GE_Editor::Application::Application()
{
	m_window = std::make_unique<GE_EngineCore::Window>();
	m_isRunning = true;
}

GE_Editor::Application::~Application()
{
	quit(); 
}

void GE_Editor::Application::run()
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
			
			GE_INFO_LOG("info log operational");

			if (win_msg.message == WM_QUIT) m_isRunning = false;

		}
		Sleep(1);
	}
}

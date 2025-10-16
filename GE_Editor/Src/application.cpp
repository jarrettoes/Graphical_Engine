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
#include <GL_init.h>
#include <GE_CoreUtilites.h>
#include <imgui.h>

GE_EDITOR::application::application()
{
	window_ptr = std::make_unique<window>();
	m_loopInit = true;
}

void GE_EDITOR::application::run_app()
{	
	if (window_ptr == nullptr)
	{
		__GE_ENGINE_ERROR_LOG("window_ptr returned nullptr");
		quit_app();
		return;
	}
	__GE_ENGINE_SUCCESS_LOG("window_ptr is successfully initalized");

	window_ptr.get()->init_window();

	gl_ptr = GE_GRAPHICS::gl_init::gl_init_instance();
	if (gl_ptr == nullptr)
	{
		__GE_ENGINE_ERROR_LOG("gl_ptr returned nullptr");
	}
	__GE_ENGINE_SUCCESS_LOG("gl_ptr is successfully initalized");


	if (window_ptr.get()->imgui_init() != EXIT_SUCCESS)
	{
		__GE_ENGINE_ERROR_LOG("something is wrong with the imGUi init");
		return;
	}

	__GE_ENGINE_SUCCESS_LOG("imgui_init successfully initalized!");


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
		
		window_ptr.get()->imgui_render_start();
		gl_ptr.get()->gl_render();
		window_ptr.get()->imgui_render_end();
		gl_ptr.get()->gl_swap_buffers(gl_ptr.get()->get_device_context());
	}
}

void GE_EDITOR::application::quit_app()
{	
	window_ptr.get()->imgui_shutdown();
	gl_ptr.get()->gl_quit();
	__GE_ENGINE_INFO_LOG("GOOD BYE MAIN LOOP");
	m_loopInit = false;
}

GE_EDITOR::application::~application()
{
	quit_app();
}
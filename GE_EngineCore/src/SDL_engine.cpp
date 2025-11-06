#include "SDL_engine.h"
#include "GE_CoreUtilites.h"
#include <SDL3/SDL.h>


void GE_ENGINE_CORE::SDL_engine::init_SDL()
{
	__GE_ENGINE_INFO_LOG("initalizing SDL");
	if ((SDL_Init(SDL_INIT_AUDIO) == -1))
	{
		__GE_ENGINE_ERROR_LOG("couldn't initalize SDL!");
		return;
	}

	__GE_ENGINE_SUCCESS_LOG("SDL is initalized successfully!");
}

void GE_ENGINE_CORE::SDL_engine::shutdown_SDL()
{
	__GE_ENGINE_INFO_LOG("shutting down SDL");
	SDL_Quit();
}

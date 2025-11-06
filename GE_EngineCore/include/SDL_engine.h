#pragma once


#ifndef SDL_ENGINE_H
#define SDL_ENGINE_H

#include "GE_EngineCore.h"
#include <memory>

namespace GE_ENGINE_CORE
{
	class GE_ENGINE_CORE_API SDL_engine
	{
		public:
			void init_SDL();
			void shutdown_SDL();

		
			static std::shared_ptr<SDL_engine> SDL_instance()
			{
				std::shared_ptr<SDL_engine> SDL_singleton = std::make_shared<SDL_engine>();
				return SDL_singleton;
			}
	};
}


#endif
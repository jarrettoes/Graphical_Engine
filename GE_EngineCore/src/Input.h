#pragma once

#ifndef INPUT_H
#define INPUT_H

#include "GE_EngineCoreAPI.h"

namespace GE_EngineCore {
	class GE_ENGINECORE_API Input
	{
		public:
		
			Input() = default;
			Input(const Input &) = delete;
			void operator=(const Input&) = delete;
			
			Input(const Input&&) = delete;
			void operator=(const Input&&) = delete;
			virtual ~Input();

		private:

			void init_func();

	};
}

#endif // !INPUT_H

#pragma once

#ifdef GE_GRAPHICS_EXPORTS
	#define GE_GRAPHICS_API __declspec(dllinport)
#else
	#define GE_GRAPHICS_API __declspec(dllexport)
#endif // GE_GRAPHICS_API

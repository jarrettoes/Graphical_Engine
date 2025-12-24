#include <iostream>
#include "core_macros.h"

using namespace core;

int main(void)
{
	ENGINE_INFO_LOG("hello");
	ENGINE_WARN_LOG("THIS IS A WARNING");
	ENGINE_SUCCESS_LOG("its working!");
	ENGINE_ERROR_LOG("its not working");
	return 0;
}
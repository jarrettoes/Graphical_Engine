#include <iostream>
#include "core_macros.h"

using namespace core;

int main(void)
{
	ENGINE_INFO_LOG("hello");
	ENGINE_WARN_LOG("THIS IS A WARNING");

	return 0;
}
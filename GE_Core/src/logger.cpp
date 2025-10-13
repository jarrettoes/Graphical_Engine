#include "logger.h"
#include <chrono>
#include <ctime>

GE_CORE::logger::~logger()
{
	std::cout << "closing logger" << std::endl;
}

#include "Profiler.h"
#include "logger.h"
#include <chrono>
#include <sstream>


const long long GE_CORE::Profiler::elapsed_time_str()
{
	auto start = std::chrono::high_resolution_clock::now();
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(start - end);
	
	return duration.count();
}


GE_CORE::Profiler::~Profiler()
{

}


#include "Profiler.h"
#include "logger.h"
#include <chrono>
#include <sstream>


void GE_CORE::Profiler::profiler_logger(const std::source_location& func_loc)
{
	//should have a switch for each time interval and which is optimal! should have its fixed string!
	std::ostringstream ss;

	ss << BACK_GREEN << "function: " << func_loc.function_name() << "ran for: " << elapsed_time_str() << "!" << std::endl;
	std::clog << ss.str();

}

const std::chrono::microseconds GE_CORE::Profiler::elapsed_time_str()
{
	auto start = std::chrono::high_resolution_clock::now();
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(start - end);
	
	return duration;
}


GE_CORE::Profiler::~Profiler()
{

}


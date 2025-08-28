#include "Logger.h"
#include <chrono>
#include <ctime>

GE_CORE::Logger::~Logger()
{

}

const std::string GE_CORE::Logger::time_stamp()
{
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    std::tm tm_buf;
#if defined(_WIN32) || defined(_WIN64)
    localtime_s(&tm_buf, &now_c); //localtime_s is depricated 
#else
    localtime_r(&now_c, &tm_buf); //believe localtime_r is aswell!
#endif
    std::ostringstream oss;
    oss << std::put_time(&tm_buf, "%m/%d/%Y %H:%M:%S: ");
    std::string formatted_time = oss.str();

   return formatted_time;
}


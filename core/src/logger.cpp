#define _CRT_SECURE_NO_WARNINGS
#define TIME_BUFFER_SIZE            20
#include "logger.h"

std::string core::logger_class::logger_timestamp()
{
    std::stringstream timestamp;

    auto now = std::chrono::system_clock::now();
    std::time_t time = std::chrono::system_clock::to_time_t(now);
    tm* local_time = std::localtime(&time);
    char timestamp_buff[TIME_BUFFER_SIZE];
    std::strftime(timestamp_buff, sizeof(timestamp_buff), "%Y-%m-%d %H:%M:%S", local_time);
    
    timestamp << "[" << timestamp_buff << "]";
    
    return timestamp.str();
}



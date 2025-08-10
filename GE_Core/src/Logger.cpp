#pragma warning(disable : 4996) // to take care of localtime_s due to depcrication

#include "Logger.h"
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>


std::string GE_CORE::Logger::logger_priority_tag(loggerPriorites priorites, const char* FILE_name, int line,
                                                 const char* function_name, const std::string& str)
{
    // for the time portion.
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    std::tm tm_buf;
#if defined(_WIN32) || defined(_WIN64)
    localtime_s(&tm_buf, &now_c); //localtime_s is depricated 
#else
    localtime_r(&now_c, &tm_buf); //believe localtime_r is aswell!
#endif
    std::ostringstream oss;
    oss << std::put_time(&tm_buf, "[%F_%T]: ");
    std::string formatted_time = oss.str();
    
    std::ostringstream priority_tag; 

    switch (priorites)
    {
        case loggerPriorites::Info:
        priority_tag << WHITE << "[INFO]";
        break;
       
        case loggerPriorites::Warning:
        priority_tag << YELLOW << "[WARNING]";
        break;

        case loggerPriorites::Error:
        priority_tag << RED << "[ERROR]";
        break;

        case loggerPriorites::Debug:
        priority_tag << MAGENTA << "[DEBUG]";
        break;

        default:
        priority_tag << WHITE << "[INFO]";
        break;
    }

    

    return 
}

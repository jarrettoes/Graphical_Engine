#pragma warning(disable : 4996)

#include "Private/Logger.h"
#include <comdef.h>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <ctime>


void GE_EngineCore::Logger::initalize_logs()
{
}

/*used a wide because we used the wide (W) function version when we did the window 32 api code. so it makes sense to do wide*/
void GE_EngineCore::Logger::warning_popup(HRESULT hres, const std::string& str)
{
	std::wstring warning_message = L"Warning! " + w_char_convert(str);
	MessageBoxW(nullptr, warning_message.c_str(), L"Warning", MB_ICONWARNING);
}

void GE_EngineCore::Logger::error_popup(HRESULT hres, const std::string& str)
{
	_com_error Error (hres);
	std::wstring error_message = L"Error! " + w_char_convert(str) + Error.ErrorMessage(); 
	MessageBoxW(nullptr, error_message.c_str(), L"Error", MB_ICONERROR);
}


std::string GE_EngineCore::Logger::handle_priority_tag(loggerPriority priority, std::string msg)
{
	std::string priority_tag;
	std::stringstream ss; 

	switch (priority)
	{
		case loggerPriority::Info:			priority_tag = "[INFO]";		break;
		case loggerPriority::Warning:		priority_tag = "???[WARNING]";		break;
		case loggerPriority::Error:			priority_tag = "!!![ERROR]";		break;
		case loggerPriority::Debug:			priority_tag = "[DEBUG]";		break;
		default:						    priority_tag = "[INFO]";		break;
	}

	ss << handle_priority_color(priority) << priority_tag << handle_time_stamp() << msg << std::endl; 

	return ss.str();
}

std::string GE_EngineCore::Logger::handle_priority_color(loggerPriority priority)
{
	std::string color_; 
	switch (priority)
	{
		case loggerPriority::Info:			color_ = WHITE;					break;
		case loggerPriority::Warning:		color_ = YELLOW;				break;
		case loggerPriority::Error:			color_ = RED;					break;
		case loggerPriority::Debug:			color_ = MAGENTA;				break;
		default:							color_ = WHITE;					break;
	}

	return color_;
}

std::string GE_EngineCore::Logger::handle_time_stamp()
{
	std::time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

	std::string s(30, '\0');
	std::strftime(&s[0], s.size(), "[%Y-%m-%d %H:%M:%S]: ", std::localtime(&now));
	return s;
}

void GE_EngineCore::Logger::clear_logs()
{
	
}

GE_EngineCore::Logger::~Logger()
{
	clear_logs(); 
}


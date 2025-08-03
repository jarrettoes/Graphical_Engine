#include "Private/Logger.h"
#include <comdef.h>
#include <chrono>


void GE_EngineCore::Logger::initalize_logs()
{
	b_initltize_logs = true;
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
std::string GE_EngineCore::Logger::handle_timestamp()
{
	auto time_now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	
	std::string time_formated = std::format({"{:%Y/%m/%d %H:%M:%S}"}, time_now);

	return time_formated; 
}
void GE_EngineCore::Logger::clear_logs()
{
	
}

GE_EngineCore::Logger::~Logger()
{
	clear_logs(); 
}


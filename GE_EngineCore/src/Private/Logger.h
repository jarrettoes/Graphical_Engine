
/********************************************************
*	  ____   _____
*	 / ___| | ____|
*	| |  _  |  _|
*	| |_| | | |___
*	 \____| |_____|
* _______________________________________________________
*
* FILE TITLE: 
*
* FILE AUTOHOR:
*
* FILE PURPOSE: 
*
*********************************************************/

#pragma once

#ifndef LOGGER_H
#define LOGGER_H

#include "Private/GE_EngineCoreAPI.h"
#include <iostream>
#include <string>
#include <Windows.h>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <unordered_map>

namespace GE_EngineCore
{

	//types of logging that we'll use for info, warning, error, and debug within the engine
	enum class GE_ENGINECORE_API loggerPriority : uint8_t
	{ Info, Warning, Error, Debug };

	enum class GE_ENGINECORE_API loggerColor : uint8_t
	{ 
		Red,
		Green,
		Orange,
		Yellow
	};

	class GE_ENGINECORE_API Logger
	{
		public:

			Logger() = default;
			~Logger();

			void initalize_logs(bool on);
			void clear_logs();
			// the template<typename .. args> will be used for multiple argument if need when logging! will keep for potenital future implmentations
			template<typename ... args>
			static void info_log(const std::string& str, args&&... arg);
			
			template<typename ... args>
			static void warning_log(const std::string& str, args&&... arg);

			template<typename ... args>
			static void error_log(const std::string& str, args&&... arg);

			template<typename ... args>
			static void debug_log(const std::string& str, args&&... arg);


			/*for popup messages within the engine!*/
			static void warning_popup(HRESULT hres, const std::string& str);
			static void error_popup(HRESULT hres, const std::string& str);

			bool check_intializeLogs() {return b_initltize_logs;}

			Logger& get_logInstance()
			{
				static Logger loggerInstance;
				return loggerInstance; 
			}

		private:

			static std::wstring w_char_convert(std::string str)
			{
				std::wstring string(str.begin() , str.end());
				return string;
			}

	
			bool b_retain_logs, b_initltize_logs;

	};

	template<typename ...args>
	inline void Logger::info_log(const std::string& str, args&& ...arg)
	{
		std::info_argument = std::vformat(str, std::make_format_args(arg...)) + "\n";
		std::cout << "[INFO]" << "[" << std::chrono::system_clock::now() << "]: " << info_argument << std::endl;
	}
	template<typename ...args>
	inline void Logger::warning_log(const std::string& str, args&& ...arg)
	{
		std::info_argument = std::vformat(str, std::make_format_args(arg...)) + "\n";
		std::cout << "[WARNING]" << "[" << std::chrono::system_clock::now() << "]: " << info_argument << std::endl;
	}
	template<typename ...args>
	inline void Logger::error_log(const std::string& str, args&& ...arg)
	{
		std::info_argument = std::vformat(str, std::make_format_args(arg...)) + "\n";
		std::cout << "[ERROR]" << "[" << std::chrono::system_clock::now() << "]: " << info_argument << std::endl;
	}
	template<typename ...args>
	inline void Logger::debug_log(const std::string& str, args&& ...arg)
	{
		std::info_argument = std::vformat(str, std::make_format_args(arg...)) + "\n";
		std::cout << "[DEBUG]" << "[" << std::chrono::system_clock::now() << "]: " << info_argument << std::endl;
	}
}

#endif 
/***********************************************************************************************************
*	  ____   _____
*	 / ___| | ____|
*	| |  _  |  _|
*	| |_| | | |___
*	 \____| |_____|
* __________________________________________________________________________________________________________
*
* FILE TITLE: 
*
* FILE AUTOHOR: 
*
* FILE PURPOSE: 
*
************************************************************************************************************/

#pragma once


#ifndef LOGGER_H
#define LOGGER_H

#define _CRT_SECURE_NO_WARNINGS

#include <GE_Core.h>
#include <iostream>
#include <cstdlib>
#include <format>
#include <iomanip>
#include <sstream>
#include <filesystem>
#include <source_location>
#include <string>

//colors for logging
#define RED			"\033[31m" 
#define WHITE		"\033[37m" 
#define MAGENTA		"\033[35m"      
#define YELLOW		"\033[33m" 
#define GREEN		"\033[32m"


namespace GE_CORE
{
	//this is the logger_priorites enum that we'll use for dictating which kind of log will be dispalyed
	enum class GE_CORE_API logger_priorites
	{
		info, warning, error, debug, success
	};

	class GE_CORE_API logger
	{
		public:
	
		//constructors	
		logger() = default;
		~logger();

		//the main logger function
		//use a varaidac template for the log_message function
		template<typename ... Arg> 
		static void log_message(const std::source_location& message_loc, logger_priorites priority, const std::string_view& msg, Arg&& ... arg);

		private:

		//to trim up the soruce_file location function name getter from void __cdecl GE_NAMESPACE::CLASS::function(void) to simply function()
		static const std::string_view clear_function_name(std::string_view function_name)
		{
			if(auto pos = function_name.find_last_of(":"); pos != std::string_view::npos) //find the last of that : within GE_NAMESPACE::CLASS::!
				return function_name.substr(pos + 1); //after that find the next ":" and do what we need to do
			return function_name;
		}
		
	};
	
	template<typename ...Arg>
	inline void logger::log_message(const std::source_location& message_loc, logger_priorites priority, const std::string_view& msg, Arg&& ...arg)
	{

		//simple time and date format for logging
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

		//a ostringstream for the soruce_location description
		std::string file_location = std::format("[ FILE: {} | FUNCTION: {} | LINE: {} ]",
			std::filesystem::path(message_loc.file_name()).filename().string(), clear_function_name(message_loc.function_name()), message_loc.line());

		std::ostringstream std_tag;

		//a switch to handle each logger priority!
		switch (priority)
		{
			case logger_priorites::info:
				std_tag << WHITE << formatted_time << "[INFO]" << "\t";
				break;

			case logger_priorites::warning:
				std_tag << YELLOW << formatted_time << "[WARN]" << "\t";
				break;

			case logger_priorites::error:
				std_tag << RED << formatted_time << "[ERROR]" << "\t";
				break;

			case logger_priorites::debug:
				std_tag << MAGENTA << formatted_time << "[DEBUG]" << "\t";
				break;

			case logger_priorites::success:
				std_tag << GREEN << formatted_time << "[SUCCESS]" << "\t";
				break;

			default:
				std_tag << WHITE << formatted_time << "[INFO]" << "\t";
				break;
		}

		//to format the msg and any potential arguments!
		std_tag << std::vformat(msg, std::make_format_args(std::forward<Arg>(arg)...)) << std::setw(200) << file_location <<  std::endl;
		
		//since its a log we should use clog instead of cout instead.
		std::clog << std_tag.str();
	}
}

#endif
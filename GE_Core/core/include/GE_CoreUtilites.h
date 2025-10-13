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

#include <iostream>
#include "logger.h"

//use __GE_ENGINE_INFO_LOG for basic information
#define __GE_ENGINE_INFO_LOG(x, ...) GE_CORE::logger::log_message(std::source_location::current(), GE_CORE::logger_priorites::info, x, __VA_ARGS__)

//use __GE_ENGINE_WARN_LOG for any potinetal warnigns that could arise from code!
#define __GE_ENGINE_WARN_LOG(x, ...) GE_CORE::logger::log_message(std::source_location::current(), GE_CORE::logger_priorites::warning, x, __VA_ARGS__)

//use __GE_ENGINE_ERROR_LOG for any errors!
#define __GE_ENGINE_ERROR_LOG(x, ...) GE_CORE::logger::log_message(std::source_location::current(), GE_CORE::logger_priorites::error, x, __VA_ARGS__)

//in contrast to __GE_ENGINE_ERROR_LOG use __GE_ENIGNE__SUCCESS_LOG to show that something succeded! 
/* (i.e)
*	if(some_ptr == NULL)
*	{
*		__GE_ENGINE_ERROR_LOG("some_ptr retunred NULL");
*		return -1;
*	}
*	
*	__GE_ENGINE_SUCCESS_LOG("some_ptr is initalized successfully!");
* 
*	things like that! 
*/
#define __GE_ENGINE_SUCESS_LOG(x, ...) GE_CORE::logger::log_message(std::source_location::current(), GE_CORE::logger_priorites::success, x, __VA_ARGS__)

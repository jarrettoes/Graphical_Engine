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

#define __GE_ENGINE_INFO_LOG(x, ...) GE_CORE::logger::log_message(std::source_location::current(), GE_CORE::logger_priorites::info, x, __VA_ARGS__)
#define __GE_ENGINE_WARN_LOG(x, ...) GE_CORE::logger::log_message(std::source_location::current(), GE_CORE::logger_priorites::warning, x, __VA_ARGS__)
#define __GE_ENGINE_ERROR_LOG(x, ...) GE_CORE::logger::log_message(std::source_location::current(), GE_CORE::logger_priorites::error, x, __VA_ARGS__)


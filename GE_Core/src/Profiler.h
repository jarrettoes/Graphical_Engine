/********************************************************
*	  ____   _____
*	 / ___| | ____|
*	| |  _  |  _|
*	| |_| | | |___
*	 \____| |_____|
* _______________________________________________________
*
* FILE TITLE: Profiler.h
*
* FILE AUTOHOR: Jarrett Williams
*
* FILE PURPOSE: to help profile any operations and extensions from logging
*
*********************************************************/

#pragma once

#ifndef PROFILER_H
#define PROFILER_H

namespace GE_CORE
{
	class Profiler 
	{
		public:
//#############################################################################################################################
// public:
//#############################################################################################################################
	
		Profiler() = default;
		Profiler(const Profiler&) = delete;
		void operator = (const Profiler&) = delete;

		Profiler(const Profiler&&) = delete;
		void operator = (const Profiler&&) = delete;
		virtual ~Profiler();

		static void profiler_logger(); 


		private:
//#############################################################################################################################
// public:
//#############################################################################################################################
		
		
	};
}


#endif
/***********************************************************************************************************
*	  ____   _____
*	 / ___| | ____|
*	| |  _  |  _|
*	| |_| | | |___
*	 \____| |_____|
* __________________________________________________________________________________________________________
*
*
*
*
*
*
*
************************************************************************************************************/

#pragma once

#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <GE_EngineCore.h>
#include <iostream>
#include <string>


namespace GE_ENGINE_CORE
{
	class GE_ENGINE_CORE_API filesystem
	{
		public:

			void open_file(const std::string& file_name, const char* type);
			void remove_file(const std::string& file_name, const char* type);

		protected:

			std::string get_file_details();

		private:

			
	};
}


#endif



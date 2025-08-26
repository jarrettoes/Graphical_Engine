#include <iostream>
#include "GE_Core\src\CoreBuild.h"

int just_run()
{
	bool run = true;
	int i = 0;
	while (run)
	{
		std::cout << "run is running" << std::endl;
		i++;
		std::cout << i << std::endl;
		
	}
	return i;
}

int main()
{
	bool m_run = true;
	int number = 5;

	GE_PROFILE_LOG(just_run);
	GE_DEBUG_LOG("debug mode activated!");
	GE_WARNING_LOG("warning is working!");
	GE_INFO_LOG("info is working!");

	while (m_run)
	{	
		
	}
	
	
	
	return 0;
}



#include <iostream>
#include <src/CoreBuild.h>


int add()
{
	return 1 + 2; 
}

int main()
{
	GE_PROFILE_LOG(add());
	
	bool m_run = true;
	int number = 5;

	GE_DEBUG_LOG("debug mode activated!"); 
	GE_INFO_LOG("hello");

	while (m_run)
	{	
		
	}
	
	
	return 0;
}



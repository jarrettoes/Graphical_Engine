#include <iostream>
#include <Windows.h>
#include <WinUser.h>

int main()
{
	HINSTANCE m_instance; 

	if(m_instance == NULL)
	{
		std::cerr << "Failed to get instance handle." << std::endl;
		m_instance = (HINSTANCE)GetModuleHandle(NULL);
	}

	WNDCLASS win_class;

}
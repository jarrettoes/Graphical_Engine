#include <iostream>
#include "application/window.hpp"

using namespace window;
int main()
{	
	Window *main_window = new Window();
	bool window_loop = true; 
	
	while (window_loop)
	{
		Sleep(10);
	}

	delete main_window;

	return 0;
}
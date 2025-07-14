#include <iostream>
#include "Application.h"

int main()
{
	try
	{
		GE_Editor::Application app{};
		app.run();
	}
	catch (std::exception& e)
	{
		std::cout << "caught runtime error in " << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

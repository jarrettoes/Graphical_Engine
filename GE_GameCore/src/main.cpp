#include <iostream>
#include <include/Game/Game.h>

using namespace GE_GameCore;
int main()
{
	try 
	{	
		Game game{}; 
		game.run(); 
	}
	catch (std::exception& e)
	{
		std::cout << "caught runtime error in " << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
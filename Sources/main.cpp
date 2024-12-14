#include "../Headers/Game.h"
#include <iostream>


int main()
{
	try {
		Game game;
		game.run();
	}
	catch (std::exception& ex) {
		std::cout << ex.what();
	}
	return 0;
}
#include <iostream>

#include "../main.hpp"
#include "../events.hpp"


Room windaParter (GameData& gameData)
{
	std::cout << "Jesteś na parterze." << std::endl;
	zaionc_event(gameData);
		
	if (gameData.zaionc) {
		std::cout << "Goni Cię zaionc." << std::endl;
		std::cout << "Uciekasz przed nim?" << std::endl;
		if (yes())
			return KORYTARZ;
		else {
			std::cout << "Zaionc Cię dopadł." << std::endl;
			gameData.alive = false;
		}
	}

	return FAIL; 
}

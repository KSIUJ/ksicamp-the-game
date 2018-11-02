#include <iostream>

#include "../main.hpp"

Room windaParter (GameData& gameData)
{

	if (gameData.zaionc) {
		std::cout << "Próbujesz zawrócić, ale zając Cię dopada." << std::endl;
		gameData.alive = false;
		return WINDA_PARTER;
	}

	zaionc_event(gameData);
		
	if (gameData.zaionc) {
		std::cout << "Goni Cię zaionc." << std::endl;
		std::cout << "Uciekasz przed nim?" << std::endl;
		if (yes())
			return KORYTARZ;
		else {
			std::cout << "Zaionc Cię dopadł." << std::endl;
			gameData.alive = false;
			return FAIL;
		}
	}

	std::cout << "Jesteś na parterze."; 
	wait_s(2);
	std::cout << std::endl;

	std::cout << "Czy chcesz wyjść na zewnątrz?" << std::endl;
	if (yes())
		return ZEWNATRZ;
	else {
		std::cout << "Czy chcesz wrócić na korytarz?" << std::endl;
		if (yes())
			return KORYTARZ;
	}

	return FAIL; 
}

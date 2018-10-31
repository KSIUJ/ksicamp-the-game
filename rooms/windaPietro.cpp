#include <iostream>

#include "../main.hpp"

Room windaPietro (GameData& gameData)
{
	std::cout << "Winda nie działa, idziesz schodami."; 
	wait_s(2);
	std::cout << std::endl;
	
	return WINDA_PARTER;
}

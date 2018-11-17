#include <iostream>

#include "../main.hpp"

Room windaPietro (__attribute__((unused))GameData& gameData)
{
	std::cout << "Winda nie działa, trzeba iść schodami."; 
	wait_s(2);
	std::cout << std::endl;

	return WINDA_PARTER;
}

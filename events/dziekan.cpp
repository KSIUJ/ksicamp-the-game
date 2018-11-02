#include <iostream>

#include "../main.hpp"

void dziekan_event (GameData& gameData) {

	if (gameData.dziekan_spotted)
		return;

	std::cout << "Spotykasz Dziekana." << std::endl
            << "Uciekasz przed nim?" << std::endl;

    if(yes()) {
        std::cout << "Przed Dziekanem się nie ucieka." << std::endl;
        gameData.alive = false;
    } else {
        std::cout << "Mówisz, \"Dzień dobry, panie Dziekanie\" "
                  << "i przechodzisz koło niego." << std::endl;
    }

	std::cout << std::endl;
	gameData.dziekan_spotted = true;
}

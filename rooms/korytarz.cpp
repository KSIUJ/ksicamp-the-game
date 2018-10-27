#include <iostream>

#include "../main.hpp"

Room korytarz(GameData& gameData) {

std::cout << "Idziesz przez korytarz. Spotykasz Dziekana." << std::endl
          << "Uciekasz przed nim?" << std::endl;

    if(yes()) {
        std::cout << "Przed Dziekanem się nie ucieka." << std::endl;
        gameData.alive = false;
    } else {
        std::cout << "Mówisz, \"Dzień dobry, panie Dziekanie\" "
                  << "i przechodzisz koło niego." << std::endl
                  << "Serwerownia jest otwarta. "
                  << "Wchodzisz do niej." << std::endl;
    }

    return SERWEROWNIA;
}
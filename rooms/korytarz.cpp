#include <iostream>

#include "../main.hpp"

Room korytarz(GameData& gameData) {

std::cout << "Idziesz przez korytarz. Serwerownia jest otwarta. "
          << "Wchodzisz do niej." << std::endl;

    return SERWEROWNIA;
}
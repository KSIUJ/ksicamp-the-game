#include <iostream>

#include "main.hpp"

Room fail(GameData& gameData) {
    std::cout << "Ten pokój nie istnieje. Spadłeś w pustkę. Elo." << std::endl;
    gameData.alive = false;
    return ZEWNATRZ;
}

bool yes() {
    char response;
    std::cin >> response;
    return strchr("YyTt", response) != nullptr;
}

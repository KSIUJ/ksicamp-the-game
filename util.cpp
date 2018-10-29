#include <iostream>
#include <algorithm>

#include "main.hpp"

Room fail(GameData& gameData) {
    std::cout << "Ten pokój nie istnieje. Spadłeś w pustkę. Elo." << std::endl;
    gameData.alive = false;
    
    return ZEWNATRZ;
}

bool yes() {
    std::string response;
    std::cin >> response;
    return strchr("YyTt", response[0]) != nullptr;
}

std::string lowercase(std::string str){
    std::string result = str;
    std::transform(str.begin(), str.end(), result.begin(), ::tolower);
    return result;
}

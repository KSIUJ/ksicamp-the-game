#include <iostream>

#include "../main.hpp"

Room ksi(GameData& gameData) {
    std::cout << "Jesteś w KSI. Słońce zaszło dawno temu. " 
              << "Coś musiało pójść bardzo nie tak." << std::endl;
    if (gameData.inventory.find("pizza") == gameData.inventory.end()) {
        std::cout  << "Obok ciebie leżą kawałki niedojedzonej pizzy. " << std::endl
                   << "Bierzesz jeden?" << std::endl;
        if (yes()) {
            std::cout << "Wziąłeś pizzę i wsadziłeś do kieszeni." << std::endl;
            gameData.inventory.insert("pizza");
        }
    } else {
        std::cout << "Nic innego tu nie ma. Jakiś żul śpi w na kanapie w kącie." << std::endl;
    }

    std::cout << "Wychodzisz na korytarz przed KSI." << std::endl;
    
    return KORYTARZ;
}


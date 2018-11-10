#include <iostream>

#include "../main.hpp"

Room serwerownia(GameData& gameData) {
    std::cout << "Wchodziś do serwerowni, nikogo tu nie ma" << std::endl;

    if (gameData.inventory.find("młotek") == gameData.inventory.end()) {
        std::cout  << "Na podłodze leży młotek." << std::endl
                   << "Bierzesz ją?" << std::endl;
        if (yes()) {
            std::cout << "Wziąłeś młotek i wsadziłeś do kieszeni." << std::endl;
            gameData.inventory.insert("młotek");
        }
    } else {
        std::cout << "Nic innego tu nie ma." << std::endl;
    }
    std::cout << "Wracasz do korytarza." << std::endl;

    return KORYTARZ;
}

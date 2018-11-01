/* 
 *	eventy mają jedno zadanie:
 *	>>  spróbować zabić gracza  <<
 *	działają na flagach, np. alive
 *	zobacz przykład użycia: rooms/korytarz.cpp 
 *
 ****************************************/

#include "events.hpp"

void dziekan_event (GameData& gameData) {

    std::cout << "Idziesz przez korytarz. Spotykasz Dziekana." << std::endl
            << "Uciekasz przed nim?" << std::endl;

    if(yes()) {
        std::cout << "Przed Dziekanem się nie ucieka." << std::endl;
        gameData.alive = false;
    } else {
        std::cout << "Mówisz, \"Dzień dobry, panie Dziekanie\" "
                  << "i przechodzisz koło niego." << std::endl;
    }
}

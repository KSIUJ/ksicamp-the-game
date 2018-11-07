#ifndef EVENTS
#define EVENTS

#include <iostream>

#include "main.hpp"

Room event_dziekan(GameData& gameData, Room dest) {
  // jesli przetrwa spotkanie z dziekanem
  std::cout << "Spotykasz Dziekana." << std::endl
            << "Uciekasz przed nim?" << std::endl;

  if (yes()) {
    std::cout << "Przed Dziekanem się nie ucieka." << std::endl;
    gameData.alive = false;
  } else {
    std::cout << "Mówisz, \"Dzień dobry, panie Dziekanie\" "
              << "i przechodzisz koło niego." << std::endl;
    return dest;
  }

  return FAIL;
}

#endif  // EVENTS

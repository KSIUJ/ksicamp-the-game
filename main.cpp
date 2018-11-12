#include <iostream>

#include "main.hpp"

void start() {
  std::cout << std::endl
            << "        **** KSICAMP - THE GAME ****" << std::endl
            << "        designed by the KSICAMP team" << std::endl
            << std::endl
            << "Obudziłeś się." << std::endl;
}

void finish(GameData& gameData) {
  std::cout << "Koniec gry." << std::endl
            << "Wynik: " << (gameData.alive ? "Wygrałeś." : "Przegrałeś.")
            << std::endl
            << "W kieszeniach masz:" << std::endl;
  if (gameData.inventory.empty()) {
    std::cout << "* nic" << std::endl;
  } else {
    for (const std::string& item : gameData.inventory) {
      std::cout << "* " << item << std::endl;
    }
  }
}

int main() {
  start();

  GameData gameData(KSI);
  do {
    gameData.room = (gameData.functions[gameData.room])(gameData);
    std::cout << std::endl;
  } while (gameData.room != ZEWNATRZ && gameData.alive);

  finish(gameData);
}

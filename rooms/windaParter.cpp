#include <iostream>

#include "../main.hpp"
#include "../GPS/gps.hpp"

Room windaParter(GameData& gameData) {
  if (gameData.zaionc) {
    std::cout << "Próbujesz zawrócić, ale zając Cię dopada." << std::endl;
    gameData.alive = false;
    return WINDA_PARTER;
  }

  zaionc_event(gameData);

  if (gameData.zaionc) {
    std::cout << "Goni Cię zaionc." << std::endl;
    std::cout << "Uciekasz przed nim?" << std::endl;
    if (yes()) {
      return KORYTARZ;
    }
    std::cout << "Zaionc Cię dopadł." << std::endl;
    wait_s(2);
    gameData.alive = false;
    return FAIL;
  }

  std::cout << "Jesteś na parterze.";
  wait_s(2);
  std::cout << std::endl;

  return gps("Dokąd idziesz?", 3, WINDA_PARTER, KORYTARZ, ZEWNATRZ);
}

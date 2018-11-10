#include <iostream>

#include "../main.hpp"

Room windyTylne(__attribute__((unused)) GameData &gameData) {
  std::cout << "Jesteś w windach tylnych" << std::endl
            << "Czy chcesz iść do biblioteki?" << std::endl;
  if (yes()) {
    return BIBLIOTEKA;
  }
  if (yes()) {
    std::cout << "Czy chcesz iść do garażu?" << std::endl;
    return GARAZ;
  }
  if (yes()) {
    std::cout << "Czy chcesz iść do windy na piętrze?" << std::endl;
    return WINDA_PIETRO;
  }
  if (yes()) {
    std::cout << "Czy chcesz iść do windy na parterze?" << std::endl;
    return WINDA_PARTER;
  }
  return WINDY_TYLNE;
}

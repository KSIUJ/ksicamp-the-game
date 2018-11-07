#include <iostream>

#include "../main.hpp"

Room windyTylne(GameData &gameData)
{
    std::cout << "Jesteś w windach tylnych" << std::endl
              << "Czy chcesz iść do biblioteki?" << std::endl;
    if (yes())
    {
        return BIBLIOTEKA;
    }
    std::cout << "Czy chcesz iść do garażu?" << std::endl;
    if (yes())
    {
        return GARAZ;
    }
    std::cout << "Czy chcesz iść do windy na piętrze?" << std::endl;
    if (yes())
    {
        return WINDA_PIETRO;
    }
    std::cout << "Czy chcesz iść do windy na parterze?" << std::endl;
    if (yes())
    {
        return WINDA_PARTER;
    }
}
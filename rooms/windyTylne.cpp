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
    else if (yes())
    {
        std::cout << "Czy chcesz iść do garażu?" << std::endl;
        return GARAZ;
    }
    else if (yes())
    {
        std::cout << "Czy chcesz iść do windy na piętrze?" << std::endl;
        return WINDA_PIETRO;
    }
    else if (yes())
    {
        std::cout << "Czy chcesz iść do windy na parterze?" << std::endl;
        return WINDA_PARTER;
    }
    else
        return WINDY_TYLNE;
}
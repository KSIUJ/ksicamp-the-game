#include <iostream>

#include "../main.hpp"

Room garaz (GameData& gameData)
{
    std::cout<<"Jestes w garazu. Jeden z samochodow ma zapalone swiatla."<<std::endl;
    std::cout<<"Moze ktos jest w srodku?"<<std::endl;
    std::cout<<"Podchodzisz sprawdzic?"<<std::endl;

    if(yes())
    {
        std::cout<<"W samochodzie siedzi Dziekan. Proponuje podwozke do Kauflanda"<<std::endl;
        return ZEWNATRZ;
    }

    std::cout<<"Samochod odjezdza, zostajesz w calkowitej ciemnosci."<<std::endl;

    if(gameData.zaionc)
    {
        std::cout<<"Z rogu garazu slychac szybki oddech..."<<std::endl;
        wait_ms(300);
        std::cout<<"TO ZAIONC"<<std::endl;
        std::cout<<"Nie masz dokad uciec"<<std::endl;
    }

    std::cout<<"Drzwi garazu sa zamkniete, mozesz tylko wrocic do windy."<<std::endl;

    return WINDY_TYLNE;
}
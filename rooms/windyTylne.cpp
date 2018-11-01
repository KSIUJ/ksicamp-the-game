#include <iostream>

#include "../main.hpp"

void start(GameData& gameData){
    std::cout << "Przechodzisz do tylnej strony budynku i widzisz " 
              << (gameData.winda_repaired ? "naprawioną przez siebę windę " : "windę, która sprawia wrażenie niedziałającej")
              << std::endl;
}

void wybor_dzialania(GameData& gameData, short i_c){
    short wybor;
    std::cout << "Co robisz?" << std::endl
              << "1. Korzystam z windy i zjeżdżam na parter" << std::endl
              << "2. Idę do windy z przodu budynku" << std::endl
              << "3. Idę do biblioteki" << std::endl
              << "4. Idę do garażu (i robię przyps)" << std::endl;
    
    bool wybor_validation;
    do{
        wybor_validation = true;

        std::cout << "> ";
        std::cin >> wybor;
        
        switch(wybor){
        case 1:
            if(!gameData.winda_repaired) {
                if(i_c == 8){
                    std::cout << "Przypominasz sobie o chińskich korzeniach i stwierdzasz, że za 8 sprawdzeniem winda na pewno będzie działać"
                              << std::endl
                              << "Naciskasz przycisk przywołania windy i w tym momencie śmiertelnie razi Cię prąd"
                              << std::endl;
                    gameData.alive = false;
                    return ZEWNATRZ;
                }
                
                std::cout << "Ślepy, czy głupi? Popsuta jest.";
                i_c++;
                
                wybor_dzialania(gameData, i_c);
            } else return WINDA_PARTER;
        
        case 2:
            return WINDA_PIETRO;

        case 3:
            return BIBLIOTEKA;

        case 4:
            return GARAZ;

        default:
            wybor_validation == false;
            std::cout << "To nie jest miejsce, którego szukasz" << std::endl
                      << "*Obi-Wan Kenobi's hand wave*" << std::endl
                      << "Wybierz raz jeszcze..." << std::endl
                      << "...tym razem mądrze, jeśli można:" << std::endl;
            break;
        }
    } while(wybor_validation == false);
}

Room windyTylne (GameData& gameData) {
    start(gameData);

    short idiot_counter=0;
    wybor_dzialania(gameData, idiot_counter);
    
    return KORYTARZ;
}


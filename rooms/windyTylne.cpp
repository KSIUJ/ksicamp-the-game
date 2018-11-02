#include <iostream>
#include <string>

#include "../main.hpp"

void start(GameData& gameData){
    std::cout << "Przechodzisz do tylnej strony budynku i widzisz " 
              << (gameData.winda_repaired ? "naprawioną przez siebę windę " : "windę, która sprawia wrażenie niedziałającej")
              << std::endl;
}

Room wybor_dzialania(GameData& gameData, short i_c){
    std::string wybor;
    while(true){
        std::cout << "Co robisz?" << std::endl;
        wait_ms(200);
        std::cout << "1. Korzystam z windy i zjeżdżam na parter" << std::endl //TODO: Add lift repair minigame
                  << "2. Idę do windy z przodu budynku" << std::endl
                  << "3. Idę do biblioteki" << std::endl
                  << "4. Idę do garażu (i robię przyps)" << std::endl
                  << "5. Wracam na korytarz" << std::endl;
    
        std::cout << "> ";
        std::cin >> wybor;
        std::cout << std::endl;

        if(wybor == "1"){
            if(!gameData.winda_repaired) {
                if(i_c == 8){
                    std::cout << "Przypominasz sobie o chińskich korzeniach i stwierdzasz, że za 8 sprawdzeniem winda na pewno będzie działać"
                              << std::endl;
                    wait_s(1);
                    std::cout << "Naciskasz przycisk przywołania windy i w tym momencie śmiertelnie razi Cię prąd"
                              << std::endl;
                    wait_s(1);
                    gameData.alive = false;
                    return ZEWNATRZ;
                }
                
                std::cout << "Ślepy, czy głupi? Popsuta jest." << std::endl;
                wait_s(1);
                i_c++;
            } else return WINDA_PARTER;
        
        } else if(wybor == "2") return WINDA_PIETRO;

        else if(wybor == "3") return BIBLIOTEKA;

        else if(wybor == "4") return GARAZ;

        else if(wybor == "5") return KORYTARZ;
        
        else { 
            std::cout << std::endl
                      << "To nie jest miejsce, którego szukasz" << std::endl
                      << "*Obi-Wan Kenobi's hand wave*" << std::endl
                      << "Wybierz raz jeszcze..." << std::endl
                      << "...tym razem mądrze, jeśli można." << std::endl << std::endl;
        }
    }
}

Room windyTylne (GameData& gameData) {
    start(gameData);

    short idiot_counter=0;
    return wybor_dzialania(gameData, idiot_counter);
    
    return KORYTARZ;
}


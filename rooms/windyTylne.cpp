#include <iostream>
#include <string>

#include "../main.hpp"

void start(GameData& gameData){
    std::cout << "Przechodzisz do tylnej strony budynku i widzisz " 
              << (gameData.winda_repaired ? "naprawioną przez siebę windę " : "windę, która sprawia wrażenie niedziałającej")
              << std::endl;
}

bool lift_repairing_game(){

};

Room wybor_dzialania(GameData& gameData, short i_c){
    std::string wybor;
    while(true){
        std::cout << "Co robisz?" << std::endl;
        wait_ms(200);
        std::cout << (gameData.winda_repaired ? "1. Korzystam z windy i zjeżdżam na parter" : "1. Podchodzę do windy, by zobaczyć czemu nie działa") << std::endl
                  << "2. Idę do windy z przodu budynku" << std::endl
                  << "3. Idę do biblioteki" << std::endl
                  << "4. Idę do garażu (i robię przyps)" << std::endl
                  << "5. Wracam na korytarz" << std::endl;

        if(yes_arg("1"){
            if(!gameData.winda_repaired) {
                std::cout << "Widzisz, migotające co jakiś czas, podświetlenie przycisku przywołania windy o jasnoniebieskim kolorze" << std::endl
                          << "Po przyjrzeniu się zauważasz, że w środku musi być jakieś zwarcie" << std::endl << std::endl
                          << "Co robisz?" << std::endl
                          << "1. Próbuję naprawić" << std::endl
                          << "2. Mam to w dupie i próbuję użyć windy" << std::endl;
                
                do{
                    if(yes_arg("1"))    if(lift_repairing_game()) gameData.winda_repaired = true;
                    
                    else if (yes_arg("1")){
                        if(i_c == 8){
                            std::cout << "Przypominasz sobie o chińskich korzeniach i stwierdzasz, że za 8 sprawdzeniem winda na pewno będzie działać"
                                    << std::endl;
                            wait_ms(500);
                            std::cout << "Naciskasz przycisk przywołania windy i w tym momencie śmiertelnie razi Cię prąd"
                                    << std::endl;
                            wait_s(1);
                            gameData.alive = false;
                            return ZEWNATRZ;
                        }
                        
                        std::cout << "Ślepy, czy głupi? Popsuta jest." << std::endl;
                        wait_s(1);
                        i_c++;
                    } else {
                        std::cout << "No debil no" << std::endl;
                    }
                }while (wybor != "1" && wybor != "2");
            } else return WINDA_PARTER;
        
        } else if(yes_arg("2")) return WINDA_PIETRO;

        else if(yes_arg("3")) return BIBLIOTEKA;

        else if(yes_arg("4")) return GARAZ;

        else if(yes_arg("5")) return KORYTARZ;
        
        else {                                      //TODO: Add waving "hand"
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


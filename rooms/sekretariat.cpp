#include <iostream>
#include <string>
#include "../main.hpp"

std::string odp;

Room sekretariat(GameData& gameData) {
    std::cout << "Jesteś w sekretariacie." 
              << "Ledwo zamknąłeś drzwi, Lembas zagrodził Ci drogę." << std::endl
              << "Zniecierpliwiony wysłuchujesz hiwait_ms(100);storii o wysyłaniu pierwszego maila w czasach paleolitu." << std::endl
              << "Jesteś odważny. Przerywasz mu." << std::endl
              << "You triggered Lemas"
              << "Dostajesz jedną szanse, jedno pytanie..." << std::endl
              << "Który język programowania jest najlepszy? " << std::endl
              << "Odpowiadasz: " << std::endl;
    wait_ms(100);
    std::cout <<".";
    wait_ms(100);
    std::cout <<".";
    wait_ms(100);
    std::cout <<".";
    std::cout << std::endl;

    std::cin >> odp;
    if(odp == "Pascal" || odp == "pascal" || odp== "PASCAL")
    {
         std::cout<<"IT'S VERY EFFECTIVE! " << std::endl
                  <<"Odpowiedziałeś dobrze i Lembas przyznaje Ci rację." << std::endl
                  <<"Niespodziewanie rozwiewa twoje wszystkie wątpliwości." << std::endl
                  <<"Spod swetra wyciąga jeden z wielu własnoręcznie podpisanych egzemplarzy "
                  <<" <<Wstępu do Informatyki>> i wręczając radzi Ci korzystać z niego mądrze." << std::endl;
        gameData.inventory.insert("podrecznik_wdi");

         std::cout<<"Odchodząc, z tylnej kieszeni wypada mu kontrowersyjne zdjęcie Kawy" << std::endl
                  <<"Podnosisz je? " << std::endl;
        if (yes()) {
            std::cout << "Nie jesteś w stanie patrzeć na zdjęcie, więc szybko chowasz je do kieszeni" << std::endl
                      << "Wiesz, że może Ci się później przydać." << std::endl;
                      wait_ms(100);
            std::cout << "W najgorszym przypadku wyląduje na twoim domowym ołtarzyku"<< std::endl;
            gameData.inventory.insert("zdjecie_kawa");
        }
                // miejsce na przejście pizzą czekających na legitymacje studentów, ale na razie nie mam czasu,
                // plus nie do końca czaję jak zaimplementować to, że ktoś coś "wykorzystuje" z inventory i potem już tego nie ma,
                // może ktoś tu robił coś podobnego, potem poszukam

        std::cout <<" Podchodzisz w końcu do upragnionej pani przy biurku." <<std::endl
                  <<" Pytasz, czy możesz przepisać się do innej grupy z Programowania 1."<< std::endl
                  <<" Uściślasz, że chcesz zamienić grupę Kawy, na grupę Szufy" << std::endl
                  <<" Pani patrzy na Ciebie z litością. Prawdziwą kurwa litością." << std::endl
                  <<" Dodaje, że wnioski leżą przy drzwiach i musisz skolekcjonować dwa podpisy prowadzących" << std::endl
                  <<" #If_that_wasn't_so_obvious" << std::endl
                  <<" Zrezygnowany opuszczasz sekretariat, chowając wniosek do kieszeni." <<std::endl
                  <<"Wiesz, że you gotta catch'em all" <<  std::endl;
                    gameData.inventory.insert("wniosek");
        //tak jak pisałem, możnaby w innych pokojach zdobywać podpis Szufy i Kawy i potem coś by się działo,
        // ale nie wiem czy chcecie ciągnąc ten pomysł
        return WINDA_PIETRO;
    }
    else
    {
        std::cout<<"Odpowiedziałeś  Ź L E" << std::endl
                 <<"Lembas każe Ci wypierdalać w podskokach  :emoticon_cry: " << std::endl;
    }   return WINDA_PIETRO;
    
}

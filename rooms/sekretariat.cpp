#include <iostream>
#include <string>
#include "../main.hpp"

Room sekretariat(GameData& gameData) {
  std::string odp;
  std::cout
      << "Jesteś w sekretariacie." << std::endl
      << "Ledwo zamknąłeś drzwi, a otyły mag w swetrze zagrodził Ci drogę. "
      << std::endl
      << "Zniecierpliwiony wysłuchujesz historii o wysyłaniu pierwszego maila "
         "w czasach paleolitu."
      << std::endl
      << "Jesteś odważny. Przerywasz mu." << std::endl;
  wait_s(5);
  std::cout << "Trigerr is comming..." << std::endl;
  wait_s(1);
  std::cout << "Dostajesz jedną szanse, jedno pytanie..." << std::endl;
  wait_s(1);
  std::cout << "." << std::endl;
  wait_s(1);
  std::cout << "." << std::endl;
  wait_s(1);
  std::cout << "." << std::endl
            << "Który język programowania jest najlepszy? " << std::endl
            << "Odpowiadasz: " << std::endl;
  std::cin >> odp;
  wait_s(1);
  std::cout << ".";
  wait_s(1);
  std::cout << ".";
  wait_s(1);
  std::cout << ".";
  std::cout << std::endl;
  if (odp == "Pascal" || odp == "pascal" || odp == "PASCAL") {
    std::cout << "IT'S VERY EFFECTIVE! " << std::endl
              << "Odpowiedziałeś dobrze i mag przyznaje Ci rację." << std::endl
              << "Niespodziewanie rozwiewa twoje wszystkie wątpliwości."
              << std::endl
              << "Spod swetra wyciąga jeden z wielu  podpisanych egzemplarzy ";
    std::cout << "<Wstępu do Informatyki> i wręczając, radzi Ci korzystać z "
                 "niego mądrze."
              << std::endl;
    gameData.inventory.insert("podrecznik_wdi");

    std::cout << "Odchodząc, z tylnej kieszeni wypada mu kontrowersyjne "
                 "zdjęcie słynnego programisty";
    std::cout << "znanego jako /Espresso/" << std::endl
              << "Podnosisz je? " << std::endl;
    if (yes()) {
      std::cout << "Nie jesteś w stanie patrzeć na zdjęcie, więc szybko "
                   "chowasz je do kieszeni"
                << std::endl
                << "Wiesz, że może Ci się później przydać." << std::endl;
      wait_s(3);
      std::cout << "W najgorszym przypadku wyląduje na twoim domowym ołtarzyku."
                << std::endl;
      gameData.inventory.insert("zdjecie");
    }
    wait_s(2);
    std::cout << "Twoim oczom ukazała się długa kolejka studentów czekających "
                 "po odbiór legitymacji."
              << std::endl
              << " Miejscami dostrzegasz rozbite namioty i rozpalone ogniska.";
    std::cout << "Do snu przygrywają im bracia Golec (sic!)" << std::endl
              << "Wiesz, że nikt darmo nie odda swojego miejsca w kolejce."
              << std::endl;

    if (gameData.inventory.find("pizza") == gameData.inventory.end()) {
      std::cout << "Gdybyś tylko miał przy sobie kawałek pizzy...";
      std::cout << "na pewno byś sobie poradził." << std::endl
                << "Obrzydzony koczownikami opuszczasz sekretariat."
                << std::endl;
      return KORYTARZ;
    }
    gameData.inventory.erase("pizza");
    std::cout << "Przypominasz sobie, że masz w kieszeni pizze... "
              << std::endl;
    std::cout << "Już wiesz co masz robić... " << std::endl;
    std::cout << "Rzucasz kawałek pizzy w kierunku wygłodzonych studentów. "
              << std::endl
              << "Mądrze wykorzystujesz zamieszanie. ";
    std::cout
        << "Podchodzisz w końcu do upragnionej pani przy biurku." << std::endl
        << "Pytasz, czy możesz przepisać się do innej grupy z Programowania "
           "1."
        << std::endl
        << "Pani patrzy na Ciebie z litością. Prawdziwą kur!#a litością."
        << std::endl
        << "Dodaje, że wnioski leżą przy drzwiach i ";
    std::cout << "musisz skolekcjonować dwa podpisy prowadzących." << std::endl
              << "#If_that_wasn't_so_obvious" << std::endl
              << "Zrezygnowany opuszczasz sekretariat, chowając wniosek do "
                 "kieszeni."
              << std::endl
              << "Wiesz, że you gotta catch'em all." << std::endl;
    gameData.inventory.insert("wniosek");
    std::cout << "Już prawie zamknąłeś drzwi, a nagle słyszysz: " << std::endl
              << "< ON MA WIĘCJE PIZZY, DARMOWA PIZZAAAA!!!  >" << std::endl
              << "Horda studentów zaczyna Cię gonić, uważaj! " << std::endl;
    return KORYTARZ;
    // ewidentnie wątek do pociągniecia dalej, jeśli ktoś chciałby się bawić
    // w pojedynek między goniącym zającem a studentami, to proszę bardzo (xD)

    // tak jak pisałem, możnaby w innych pokojach zdobywać podpis i potem coś by
    // się działo ale nie wiem czy chcecie ciągnąc ten pomysł
  }
    std::cout << "Odpowiedziałeś  Ź L E" << std::endl
              << "Mag każe Ci opuścić jego teren w podskokach  :emoticon_cry:"
              << std::endl;

  return KORYTARZ;
}

#include <iostream>
#include "../main.hpp"

Room biblioteka(GameData &gameData) {
  if (gameData.zaionc) {
    std::cout << "Wpadasz do bibliteki, ZAIONC wciąż Cię goni." << std::endl
              << "Ukrywasz się między regałami, licząc, że ZAIONC nie wykryje "
                 "Cię swoim ekstra nosem."
              << std::endl
              << "Jednak, jak mówi klasyk, NIC BARDZIEJ MYLNEGO" << std::endl
              << "Na widok ZAIONCA uderzasz o regał, z którego na twoją głowę "
                 "spada święta księga autorstwa Cormena"
              << std::endl;
    wait_s(2);
    gameData.alive = false;
    return FAIL;
  }

  std::cout << "Trafiasz do biblioteki. Słyszałeś o klątwie Kawy która dotknie "
               "każdego, kto pobierze PDF-a jego książki."
            << std::endl
            << "Kody tego nieszczęśnika nigdy nie wejdą na BaCę, stanie się "
               "stworzeniem tak nieczystym, że biały pył kredy nie będzie na "
               "nim osiadał."
            << std::endl
            << "W bibliotece nie ma jednak książki Kawy. Ponoszą Cię nerwy, "
               "czy szukasz PDF-a w internecie?"
            << std::endl;
  if (yes()) {
    std::cout
        << "Źle postąpiłeś. Kawa zobaczył że kreda na tobie nie osiada. Nie "
           "zapytał Cię na ćwiczeniach ani raz czy masz jakieś pytania."
        << std::endl
        << "Załamany postanawiasz skończyć ze sobą. Rzucasz się z okna."
        << std::endl;
    wait_s(2);
    gameData.alive = false;
    return FAIL;
  }
    std::cout << "Młody, SZACUN RISPEKT, dr. Kawa był by z Ciebie dumny."
              << std::endl;
    wait_s(2);
    return WINDY_TYLNE;
}

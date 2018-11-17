#include <cstdlib>
#include <iostream>
#include <random>
#include <string>

#include "../main.hpp"

const int8_t minigame_row = 3;
const int8_t minigame_col = 3;

void start(GameData& gameData) {
  std::cout << "Przechodzisz do tylnej strony budynku i widzisz "
            << (gameData.winda_repaired
                ? "naprawioną przez siebę windę "
                : "windę, która sprawia wrażenie niedziałającej")
            << std::endl;
}
/*
void draw_minigame(char k[][minigame_col+2], short off[minigame_col]) {
    std::cout << "Not yet implemented" << std::endl;
}
*/
void input_prompt(std::string& s) {
  std::cout << "> ";
  std::cin >> s;
}

bool lift_repairing_game(GameData& gameData) {  // TODO(seqre): Add minigame
  int choice;
  std::cout << "Po chwili dochodzisz do wniosku, że bez ściągnięcia"
            << "zewnętrznej osłony nic nie zdziałasz" << std::endl;
  if (gameData.inventory.find("śrubokręt") != gameData.inventory.end()) {
    std::cout
        << "Odkręcasz śrubki trzymające ochronną płytkę i ostrożnie ją ściągasz"
        << " podważając śrubokrętem" << std::endl
        << "Widzisz porwane kable bez izolacji, które czasami się stykając"
        << "tworzą efektowne zwarcia" << std::endl;

    choice = responsive_menu("Co robisz?",
                             "Naprawiam dalej",
                             "Odpuszczam i przykręcam płytkę z powrotem");
    if (choice == 1) {
      std::cout << "Not implemented yet" << std::endl;
      /*
      std::cout << "Po chwili analizowania kabli stwierdzasz, że jak je
      poprzesuwasz i odpowiednio połączysz"
                << " to przyciski powinny zacząć działać" << std::endl;

      bool kable_poprawnie = false;
      bool ruch = false;

      char kable [minigame_row][minigame_col+2] {};
      short offset [minigame_col] {};

      while(kable_poprawnie) {
          while(!ruch) {
              clear_screen();
              draw_minigame(kable, offset);
          }

      }
      */
      return false;
    }
    return false;
  }
  std::cout << "Niestety, ale nie masz potrzebnego narzędzia do tego, wróć "
               "później jak je zdobędziesz"
            << std::endl;
  return false;
}

template <typename S>
std::string concatenate(S s) {
  return s;
}

template <typename S, typename... Args>
std::string concatenate(S s, Args... args) {
  return (s + concatenate(args...));
}

int  choose_room_text(GameData& gameData) {
  return responsive_menu("Co robisz?",
                        (gameData.winda_repaired?
                        "Korzystam z windy i zjeżdżam na parter"
                        : "Podchodzę do windy, by zobaczyć czemu nie działa"),
                        (concatenate((gameData.zaionc ? "Biegnę" : "Idę"), " do windy z przodu budynku")),
                        (concatenate((gameData.zaionc ? "Biegnę" : "Idę"), " do biblioteki")),
                        (concatenate((gameData.zaionc ? "Biegnę" : "Idę"), " do garażu (i robię przyps)")),
                        (concatenate("Wracam ", (gameData.zaionc ? "biegiem" : ""), "na korytarz")));
}

Room choose_room(GameData& gameData, int8_t inside_idiot_counter) {
  int choice;

  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> rand_val(0, 9);

  while (true) {
    choice = choose_room_text(gameData);

    switch (choice) {
      case 1:
        if (!gameData.winda_repaired) {
          std::cout << "Widzisz, migotające co jakiś czas, podświetlenie "
                    << "przycisku przywołania windy o jasnoniebieskim kolorze"
                    << std::endl
                    << "Po przyjrzeniu się zauważasz, że w środku musi być "
                    << "jakieś zwarcie" << std::endl
                    << std::endl;

          do {
            choice = responsive_menu("Co robisz?",
                                     "Próbuję naprawić",
                                     "Mam to w głęboko i próbuję użyć windy");

            switch (choice) {
              case 1:
                std::cout << "Not implemented yet" << std::endl;
                return WINDY_TYLNE;
                // if(lift_repairing_game(gameData)) gameData.winda_repaired =
                // true;
                break;

              case 2:
                if (inside_idiot_counter == 8) {
                  std::cout
                      << "Przypominasz sobie o chińskich korzeniach i "
                         "stwierdzasz, że za 8 sprawdzeniem winda na pewno "
                         "będzie działać"
                      << std::endl;
                  wait_ms(500);
                  std::cout << "Naciskasz przycisk przywołania windy i w tym "
                               "momencie śmiertelnie razi Cię prąd"
                            << std::endl;
                  wait_s(1);
                  gameData.alive = false;
                  return ZEWNATRZ;
                }

                std::cout << "Ślepy, czy głupi? Popsuta jest." << std::endl;
                wait_s(1);
                inside_idiot_counter++;
                break;

              default:
                std::cout << "No debil no" << std::endl << std::endl;
                break;
            }
          } while (choice != 1 && choice != 2);

        } else {
          return WINDA_PARTER;
        }
        break;

      case 2:
        return WINDA_PIETRO;
        break;

      case 3:
        return BIBLIOTEKA;
        break;

      case 4:
        return GARAZ;
        break;

      case 5:
        return KORYTARZ;
        break;

      default:  // TODO(seqre): Add waving "hand"
        std::cout << std::endl
                  << std::endl
                  << "To nie jest miejsce, którego szukasz" << std::endl
                  << "*Obi-Wan Kenobi's hand wave*" << std::endl
                  << "Wybierz raz jeszcze..." << std::endl
                  << "...tym razem mądrze, jeśli można." << std::endl
                  << std::endl;
        break;
    }
  }
}

Room choose_room_zaionc(GameData& gameData) {
  int choice;

  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> rand_val(0, 9);

  while (true) {
    choice = choose_room_text(gameData);

    switch (choice) {
      case 1:
        if (!gameData.winda_repaired) {
          std::cout << "Jesteś debil, bo zamiast uciekać sprawdzasz windę"
                    << std::endl;
          gameData.alive = false;
          return ZEWNATRZ;
        } else if (rand_val(gen) % 10 > 0) {
          std::cout << "Widzisz jak w ostatniej chwili drzwi od windy "
                    << "zamykają się przed zaioncem" << std::endl;
          return WINDA_PARTER;
        } else {
          std::cout << "Niestety, ale zaionc był szybszy od windy" << std::endl;
          gameData.alive = false;
          return ZEWNATRZ;
        }
        break;

      case 2:
        if (rand_val(gen) % 10 > 0) {
          std::cout << "Widzisz jak w ostatniej chwili drzwi od windy zamykają "
                    << "się przed zaioncem" << std::endl;
          return WINDA_PIETRO;
        } else {
          std::cout << "Niestety, ale zaionc był szybszy od windy" << std::endl;
          gameData.alive = false;
          return ZEWNATRZ;
        }
        break;

      case 3:
        return BIBLIOTEKA;
        break;

      case 4:
        return GARAZ;
        break;

      case 5:
        return KORYTARZ;
        break;
      default:
        std::cout << "Twoje niezdecydowanie działa na korzyść zaionca"
                  << std::endl;
        gameData.alive = false;
        return ZEWNATRZ;
        break;
    }
  }
}

Room windyTylne(GameData& gameData) {
  start(gameData);

  int j = responsive_menu("Co robisz?",
                          "Próbuję naprawić",
                          "Mam to w głęboko i próbuję użyć windy",
                          concatenate("Yolo ", "xD"));
    std::cout << j;

  int8_t idiot_counter = 0;

  return (gameData.zaionc ? choose_room_zaionc(gameData)
                          : choose_room(gameData, idiot_counter));
}

#include <algorithm>
#include <chrono>  // std::chrono::microseconds
#include <iostream>
#include <string>
#include <thread>  // std::this_thread::sleep_for;

#include "main.hpp"

std::string RoomToString(int RoomId) {
  std::string roomStrings[] = {"KSI",
                               "KORYTARZ",
                               "SERWEROWNIA",
                               "WC",
                               "WINDA (PIĘTRO)",
                               "WINDA (PARTER)",
                               "WINDA (TYLNA)",
                               "GARAŻ",
                               "ZEWNĄTRZ",
                               "BIBLIOTEKA",
                               "FAIL"};
  return roomStrings[RoomId];
}

Room fail(GameData& gameData) {
  std::cout << "Ten pokój nie istnieje. Spadłeś w pustkę. Elo." << std::endl;
  gameData.alive = false;

  return ZEWNATRZ;
}

bool yes() {
  std::cout << ">";  // prompt, użytkownik wie że czas na jego ruch
  std::string response;
  std::cin >> response;
  return strchr("YyTt", response[0]) != nullptr;
}

std::string lowercase(std::string str) {
  std::string result = str;
  std::transform(str.begin(), str.end(), result.begin(), ::tolower);
  return result;
}

void wait_s(unsigned int secs) {  // wstrzymuje wątek na secs sekund
  std::cout.flush();              // może tu być? del comment jeśli tak
  std::this_thread::sleep_for(std::chrono::seconds(secs));
}

void wait_ms(unsigned int millisecs) {  // wstrzymuje wątek
  std::cout.flush();                    // na millisecs milisekund
  std::this_thread::sleep_for(std::chrono::milliseconds(millisecs));
}

void print_text(std::string text) {
  for (char i : text) {
    std::cout << i;
    wait_ms(20);
  }
  std::cout << std::endl;
}

int choice(int n) {
  std::string response;
  std::cout << "> ";
  std::cin >> response;

  if (n < 10) {
    if (isdigit(response[0]) != 0) {
      if ((static_cast<int>(response[0]) - 48) <= n) {
        return response[0];
      }
      { return 0; }
    } else {
      return 0;
    }
  } else {
    return 0;
  }
}

template <typename X, typename T>
int responsive_menu_tech(X x, T t) {
  std::cout << x << ". " << t << std::endl;
  int wyb = choice(x);
  return (wyb > 0 ? wyb - 48 : 0);
}

template <typename X, typename T, typename... Args>
int responsive_menu_tech(X x, T t, Args... args) {
  std::cout << x << ". " << t << std::endl;
  x++;

  return responsive_menu_tech(x, args...);
}

template <typename... Args>
int responsive_menu(Args... args) {
  return responsive_menu_tech(1, args...);
}

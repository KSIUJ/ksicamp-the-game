#include <algorithm>
#include <chrono>  // std::chrono::microseconds
#include <string>
#include <thread>  // std::this_thread::sleep_for;
#include <cstdlib>
#include <iostream>

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
  int response;
  std::cout << "> ";
  std::cin >> response;

  if (std::cin.good()) {
    if (response > 0 && response <= n ) {
      return response;
    } else {
      return 0;
    }
  } else {
    std::cin.clear();
    std::cin.sync();
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

template <typename C, typename... Args>
int responsive_menu(C c, Args... args) {
  std::cout << c << std::endl;
  return responsive_menu_tech(1, args...);
}

bool yes(const std::string& s) {
  std::cout << "> ";
  std::string response;
  std::cin >> response;
  return strchr(s.c_str(), response[0]) != nullptr;
}

void clear_screen() {
#ifdef _WIN32
  std::system("cls");
#endif

#ifdef unix
  std::cout << "\033[2J";
#endif
}

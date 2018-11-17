#ifndef MAIN_HPP_
#define MAIN_HPP_

#include <cctype>
#include <cstring>
#include <random>
#include <set>
#include <string>
#include <iostream>

enum Room {  // UWAGA! robisz coś tu? popraw w util.cpp RoomToString!
  KSI,
  KORYTARZ,
  SERWEROWNIA,
  WC,
  WINDA_PIETRO,
  WINDA_PARTER,
  WINDY_TYLNE,
  GARAZ,
  ZEWNATRZ,
  BIBLIOTEKA,
  FAIL,
  ROOM_SIZE,  // enum size marker
};

std::string RoomToString(int RoomId);

class GameData;

Room fail(GameData& gameData);
Room ksi(GameData& gameData);
Room korytarz(GameData& gameData);
Room wc(GameData& gameData);
Room serwerownia(GameData& gameData);
Room windaPietro(GameData& gameData);
Room windaParter(GameData& gameData);
Room windyTylne(GameData& gameData);
Room biblioteka(GameData& gameData);
Room garaz(GameData& gameData);
Room zewnatrz(GameData& gameData);

class GameData {
 public:
  Room (*functions[ROOM_SIZE])(GameData&);
  bool alive = true;
  bool zaionc = false;
  bool zaionc_KSI = false;
  bool dziekan_spotted = false;
  bool winda_repaired = false;
  std::set<std::string> inventory;
  Room room;

  explicit GameData(Room room) {
    this->room = room;
    this->functions[KSI] = &ksi;
    this->functions[KORYTARZ] = &korytarz;
    this->functions[WC] = &wc;
    this->functions[SERWEROWNIA] = &serwerownia;
    this->functions[WINDA_PIETRO] = &windaPietro;
    this->functions[WINDA_PARTER] = &windaParter;
    this->functions[WINDY_TYLNE] = &windyTylne;
    this->functions[GARAZ] = &garaz;
    this->functions[ZEWNATRZ] = &fail;
    this->functions[FAIL] = &fail;
    this->functions[BIBLIOTEKA] = &biblioteka;
  }
};

bool yes(const std::string& s = "yYtT");

std::string lowercase(std::string str);

void wait_s(unsigned int secs);
void wait_ms(unsigned int millisecs);

void dziekan_event(GameData& gameData);
void zaionc_event(GameData& gameData);

void print_text(std::string text);
void clear_screen();

int choice(int n);

template <typename X, typename T>
int responsive_menu_tech(X x, T t) {
  std::cout << x << ". " << t << std::endl;
  int wyb = choice(x);

  return (wyb > 0 ? wyb : 0);
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

#endif  // MAIN_HPP_

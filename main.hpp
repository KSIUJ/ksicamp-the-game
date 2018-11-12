#ifndef MAIN_HPP_
#define MAIN_HPP_

#include <cstring>
#include <set>
#include <string>

enum Room {
  KSI,
  KORYTARZ,
  SERWEROWNIA,
  WC,
  WINDA_PIETRO,
  WINDA_PARTER,
  WINDY_TYLNE,
  GARAZ,
  ZEWNATRZ,
  FAIL,
  BIBLIOTEKA,
  ROOM_SIZE,  // enum size marker
};

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
  std::set<std::string> inventory;
  Room room;

  explicit GameData(Room room) {
    this->room = room;
    this->functions[KSI] = &ksi;
    this->functions[KORYTARZ] = &korytarz;
    this->functions[WC] = &wc;
    this->functions[SERWEROWNIA] = &fail;
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

#endif  // MAIN_HPP_

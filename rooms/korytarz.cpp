#include <iostream>
#include <unordered_map>

#include "../main.hpp"

class DestinationMap {
  std::unordered_map<std::string, Room> destination_map;

 public:
  DestinationMap() noexcept {
    destination_map["1"] = SERWEROWNIA;
    destination_map["serwerownia"] = SERWEROWNIA;
    destination_map["2"] = WC;
    destination_map["wc"] = WC;
    destination_map["3"] = WINDA_PIETRO;
    destination_map["winda"] = WINDA_PIETRO;
    destination_map["4"] = KSI;
    destination_map["ksi"] = KSI;
  }

  Room operator[](const std::string& key) {
    if (this->destination_map.find(key) != this->destination_map.end()) {
      return this->destination_map[key];
    }
    return FAIL;
  }
};

static DestinationMap destination_map;

Room leave_korytarz() {
  std::string destination;

  while (true) {
    std::cout << "Dokąd dalej?" << std::endl
              << "1) Serwerownia" << std::endl
              << "2) WC" << std::endl
              << "3) Winda" << std::endl
              << "4) KSI" << std::endl;

    std::cin >> destination;
    std::cout << "Idziesz w stronę " << destination << std::endl;

    if (destination_map[lowercase(destination)] != FAIL) {
      return destination_map[destination];
    }

    std::cout << "Nie ma takiego pomieszczenia. Jesteś w korytarzu."
              << std::endl
              << std::endl;
  }
}

Room korytarz(GameData& gameData) {
  std::cout << (gameData.zaionc ? "Goni Cię zając. Uciekasz" : "Idziesz");
  std::cout << " przez korytarz." << std::endl;

  if (!gameData.dziekan_spotted) {
    std::cout << "Spotykasz Dziekana." << std::endl
              << "Uciekasz przed nim?" << std::endl;

    if (yes()) {
      std::cout << "Przed Dziekanem się nie ucieka." << std::endl;
      gameData.alive = false;
    } else {
      std::cout << "Mówisz, \"Dzień dobry, panie Dziekanie\" "
                << "i przechodzisz koło niego." << std::endl;
    }

    std::cout << std::endl;
    gameData.dziekan_spotted = true;
  }

  if (gameData.alive) {
    return leave_korytarz();
  }
  { return KORYTARZ; }
}

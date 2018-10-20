#ifndef KSI_MAIN_HPP
#define KSI_MAIN_HPP

#include <set>
#include <string>
#include <cstring>

enum Room {
    KSI, KORYTARZ, SERWEROWNIA, WINDA_PIETRO, WINDA_PARTER, WINDY_TYLNE, GARAZ, ZEWNATRZ, ROOM_SIZE
};

class GameData;

Room fail(GameData& gameData);
Room ksi(GameData& gameData);
// Room korytarz(GameData& gameData);
// Room serwerownia(GameData& gameData);
// Room windaPietro(GameData& gameData);
// Room windaParter(GameData& gameData);
// Room windyTylne(GameData& gameData);
// Room garaz(GameData& gameData);
// Room zewnatrz(GameData& gameData);

class GameData {
public:
    Room (* functions[ROOM_SIZE])(GameData&);
    std::set<std::string> inventory;
    bool alive = true;
    Room room = KSI;

    GameData() {
        this->functions[KSI] = &ksi;
        this->functions[KORYTARZ] = &fail;
        this->functions[SERWEROWNIA] = &fail;
        this->functions[WINDA_PIETRO] = &fail;
        this->functions[WINDA_PARTER] = &fail;
        this->functions[WINDY_TYLNE] = &fail;
        this->functions[GARAZ] = &fail;
        this->functions[ZEWNATRZ] = &fail;
    }
};

bool yes();

#endif //KSI_MAIN_HPP
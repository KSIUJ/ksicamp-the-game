#include <iostream>
#include <unordered_map>
#include <algorithm>

#include "../main.hpp"

class DestinationMap {
    std::unordered_map<std::string, Room> destination_map;
    
    public:
        DestinationMap() {
            destination_map["WC"] = WC;
            destination_map["Winda"] = WINDA_PIETRO;
            destination_map["KSI"] = KSI;
            destination_map["Serwerownia"] = SERWEROWNIA;
        }

        Room operator[](std::string key){
            if(this->destination_map.find(key) != this->destination_map.end()) {
                return this->destination_map[key];
            } else {
                return FAIL;
            }
        }
};

static DestinationMap destination_map;

Room leave_korytarz() {
    std::string destination;
    std::locale loc;

    while(true){
        std::cout << "Dokąd dalej? (Skopiuj jedną z tych nazw)" << std::endl
                    << "Serweronia" << std::endl
                    << "WC" << std::endl
                    << "Winda" << std::endl
                    << "KSI" << std::endl;
        
        std::cin  >> destination;
        std::cout << "Idziesz w stronę " << destination << std::endl;

        if(destination_map[destination] != FAIL){
            return destination_map[destination];
        }

        std::cout << "Nie ma takiego pomieszczenia. Jesteś w korytarzu." << std::endl << std::endl;
    }
}

Room korytarz(GameData& gameData) {

    std::cout << "Idziesz przez korytarz. Spotykasz Dziekana." << std::endl
            << "Uciekasz przed nim?" << std::endl;

    if(yes()) {
        std::cout << "Przed Dziekanem się nie ucieka." << std::endl;
        gameData.alive = false;
    } else {
        std::cout << "Mówisz, \"Dzień dobry, panie Dziekanie\" "
                  << "i przechodzisz koło niego." << std::endl;
                //   << "Serwerownia jest otwarta. "
                //   << "Wchodzisz do niej." << std::endl;    
        return leave_korytarz();    
    }

    return KORYTARZ;
}
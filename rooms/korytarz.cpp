#include <iostream>
#include <unordered_map>
#include <algorithm>

#include "../main.hpp"

class DestinationMap {
    std::unordered_map<std::string, Room> destination_map;
    
    public:
        DestinationMap() {
            destination_map["1"] = SERWEROWNIA;
            destination_map["Serwerownia"] = SERWEROWNIA;
            destination_map["2"] = WC;
            destination_map["WC"] = WC;
            destination_map["3"] = WINDA_PIETRO;
            destination_map["Winda"] = WINDA_PIETRO;
            destination_map["4"] = KSI;
            destination_map["KSI"] = KSI;
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

// string tolower(std::string str){
//     std::string result;
//     return std::transform(str.begin(), str.end(), )
// }

Room leave_korytarz() {
    std::string destination;

    while(true){
        std::cout << "Dokąd dalej?" << std::endl
                    << "1) Serweronia" << std::endl
                    << "2) WC" << std::endl
                    << "3) Winda" << std::endl
                    << "4) KSI" << std::endl;
        
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
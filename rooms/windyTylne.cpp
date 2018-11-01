#include <iostream>

#include "../main.hpp"

void start(GameData& gameData){
    std::cout << "Przechodzisz do tylnej strony budynku i widzisz " 
              << gameData.winda_repaired? "naprawioną przez siebę windę " : "windę, która sprawia wrażenie niedziałającej"
              << std::endl
              << "Co robisz?"
              << std::endl;
}

Room windyTylne (GameData& gameData) {
    start(gameData);
    
    return KORYTARZ;
}


#include <iostream>
#include <algorithm>
#include <chrono> // std::chrono::microseconds
#include <thread> // std::this_thread::sleep_for;

#include "main.hpp"

Room fail(GameData& gameData) {
    std::cout << "Ten pokój nie istnieje. Spadłeś w pustkę. Elo." << std::endl;
    gameData.alive = false;
    
    return ZEWNATRZ;
}

bool yes() {
	std::cout << ">"; // prompt, użytkownik wie że czas na jego ruch
    std::string response;
    std::cin >> response;
    return strchr("YyTt", response[0]) != nullptr;
}

std::string lowercase(std::string str){
    std::string result = str;
    std::transform(str.begin(), str.end(), result.begin(), ::tolower);
    return result;
}


void wait_s (unsigned int secs) {	// wstrzymuje wątek na secs sekund 
	std::cout.flush();	// może tu być? del comment jeśli tak
	std::this_thread::sleep_for(std::chrono::seconds(secs));
}


void wait_ms (unsigned int millisecs) {	// wstrzymuje wątek
	std::cout.flush();					// na millisecs milisekund 
	std::this_thread::sleep_for(std::chrono::milliseconds(millisecs));
}

bool yes_arg(std::string s) {
	std::cout << ">"; // prompt, użytkownik wie że czas na jego ruch
    std::string response;
    std::cin >> response;
    return strchr(s.c_str(), response[0]) != nullptr;
}
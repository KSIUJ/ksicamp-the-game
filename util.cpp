#include <algorithm>
#include <chrono> // std::chrono::microseconds
#include <thread> // std::this_thread::sleep_for;
#include <cstdlib>
#include <iostream>

#include "main.hpp"

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

bool yes(const std::string& s) {
	std::cout << "> "; // prompt, użytkownik wie że czas na jego ruch
    std::string response;
    std::cin >> response;
    return strchr(s.c_str(), response[0]) != nullptr;
}

void clear_screen(){
#ifdef WINDOWS
    std::system("cls");
#else
    // Assume POSIX
    std::system("clear");
#endif
}
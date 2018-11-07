#include <iostream>

#include "../main.hpp"

Room ksi(GameData& gameData) {

	if (gameData.zaionc) {
		std::cout << "Wpadasz do KSI. Phoe obudził się, ";
		std::cout << "stoi na środku pokoju." << std::endl;	
		std::cout << "Do pokoju wpada zaionc, rzuca się na Ciebie." << std::endl;	
		std::cout << "W ostatniej chwili uchylasz się niczym Neo," << std::endl;	
		std::cout << "unikając zaionca, który nie trafiając w Ciebie" << std::endl;	
		std::cout << "szybuje w stronę Phoe." << std::endl;	
		std::cout << std::endl;	

		std::cout << "To dobry moment na ucieczkę, wybiegasz na korytarz." << std::endl;	
		gameData.zaionc = false;
		gameData.zaionc_KSI = true;
		return KORYTARZ;
	}

	if (gameData.zaionc_KSI) {
		std::cout << "Phoe z zaioncem śpią na kanapie." << std::endl;
		std::cout << "Chyba lepiej ich nie budzić." << std::endl;
	} else {
	    std::cout << "Jesteś w KSI. Słońce zaszło dawno temu. " 
              << "Coś musiało pójść bardzo nie tak." << std::endl;
	}

    if (gameData.inventory.find("pizza") == gameData.inventory.end()) {
        std::cout  << "Obok ciebie leżą kawałki niedojedzonej pizzy. " << std::endl
                   << "Bierzesz jeden?" << std::endl;
        if (yes()) {
            std::cout << "Wziąłeś pizzę i wsadziłeś do kieszeni." << std::endl;
            gameData.inventory.insert("pizza");
        }
    } else {
        std::cout << "Nic innego tu nie ma."
			<< (gameData.zaionc_KSI ? "" : "Jakiś Phoe śpi w na kanapie w kącie.") << std::endl;
    }

    std::cout << "Wychodzisz na korytarz przed KSI." << std::endl;
    
    return KORYTARZ;
}


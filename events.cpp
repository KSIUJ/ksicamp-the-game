/* 
 *	eventy mogą np:
 *	>>  spróbować zabić gracza  <<
 *	>>  być szansą na zdobycie czegoś (marchewki?)  <<
 *	działają na flagach, np. alive
 *	zobacz przykład użycia: rooms/korytarz.cpp 
 *
 *
 *
 ****************************************/

#include "events.hpp"

void dziekan_event (GameData& gameData) {

	if (gameData.dziekan_spotted)
		return;

	std::cout << "Spotykasz Dziekana." << std::endl
            << "Uciekasz przed nim?" << std::endl;

    if(yes()) {
        std::cout << "Przed Dziekanem się nie ucieka." << std::endl;
        gameData.alive = false;
    } else {
        std::cout << "Mówisz, \"Dzień dobry, panie Dziekanie\" "
                  << "i przechodzisz koło niego." << std::endl;
    }

	std::cout << std::endl;
	gameData.dziekan_spotted = true;
}


void zaionc_event (GameData& gameData) {

	wait_s(2); std::cout << std::endl; 
	std::cout << "Słyszysz niepokojące odgłosy ";

	wait_s(2);

	for (int i=3; i>0; --i) {
		std::cout << "."; 
		wait_ms(200);
	}


	wait_s(4);

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "                             `/shmNNNNNmdyo:`                                   " << std::endl;
	std::cout << "                          `+dMNho/--.--:+shNMh:                                 " << std::endl;
	std::cout << "                       :mMh-                 -MM-    `.://////-.                " << std::endl;
	std::cout << "                      oMN/                    mMo:ohNMMNmddddmNMNdo-            " << std::endl;
	std::cout << "                   yMd`                  -yMNy-                     sMd         " << std::endl;
	std::cout << "                 /MN-               `omMd/                         `dMy         " << std::endl;
	std::cout << "               `mMs             :hMNo`                          -yMNo           " << std::endl;
	std::cout << "              +MN.         `omMh:                        `/smMNy:               " << std::endl;
	std::cout << "          `:omMMdddddddddMMMMNNNNNNNNNNNNNNNNNNNNNNNMMNs/.                      " << std::endl;
	std::cout << "        :hMNhs+//////////////:::::::::::::::::////+oymMNy:                      " << std::endl;
	std::cout << "     `mMy:.                     :                        -dMd-                  " << std::endl;
	std::cout << "     hMh oy/.                .:sy`                         oMN:                 " << std::endl;
	std::cout << "    -MM- -syyhs++/.    `:++ohhyy/                           /MM:                " << std::endl;
	std::cout << "    +Mm    -://:.        `-///-`                             +MN.               " << std::endl;
	std::cout << "    +Mm`           .o.                                        -MM.              " << std::endl;
	std::cout << "    `NM/    `++o+o+o++o+o+ooo-                                 mMo              " << std::endl;
	std::cout << "     /MN:    :::::::/:::::::/`                                 sMh              " << std::endl;
	std::cout << "      .hMNo.                                                   +MN:-`           " << std::endl;
	std::cout << "         -smMNhso+//-                                          +MMNNMNh+`       " << std::endl;
	std::cout << "            ./oyyhNMo                                          +Mm``./yMNo      " << std::endl;
	std::cout << "                  dMo   :ys    oy/           `-+osssssssso     +Mm`    .mMs     " << std::endl;
	std::cout << "                  dMo   +MN    hMs         /hNMdysooooooo+     +Mm`     sMd     " << std::endl;
	std::cout << "                  sMd-..oMN....dMy.......dMh...............----oMN:/ohNMh-      " << std::endl;
	std::cout << "                  `omMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNmhs/`        ";
	
	wait_s(2);

	std::cout << std::endl << std::endl << "TO WŚCIEKŁY ZAIONC ";

	wait_s(1);
	
	for (int i=30; i>0; --i) {
		wait_ms(20);
		std::cout << "!";
	}

	for (int i=9; i>0; --i) {
		wait_ms(20);
		std::cout << "1";
	}

	for (int i=8; i>0; --i) {
		wait_ms(20);
		std::cout << "@";
	}

	wait_s(2);

	std::cout << std:: endl;


	gameData.zaionc = true;
}

#include <iostream>

#include "../main.hpp"



Room windaParter (GameData& gameData)
{
	std::cout << "Jesteś na parterze, niedaleko windy." << std::endl
				<< "Słyszysz niepokojące odgłosy";

	for (int i=3; i>0; --i) {
		std::cout << "."; 
		wait_s(1);
	}

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
	
	wait_s(5);

	std::cout << std::endl << "TO WŚCIEKŁY ZAIONC ";
	
	for (int i=30; i>0; --i) {
		wait_ms(50);
		std::cout << "!";
	}

	for (int i=6; i>0; --i) {
		wait_ms(100);
		std::cout << "1";
	}

	for (int i=6; i>0; --i) {
		wait_ms(250);
		std::cout << "@";
	}

	std::cout << std:: endl;


	gameData.zaionc = true;
	gameData.alive = false;
	return FAIL; 
}

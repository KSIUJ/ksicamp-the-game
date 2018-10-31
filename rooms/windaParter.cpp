#include <iostream>
#include <chrono> // std::chrono::microseconds
#include <thread> // std::this_thread::sleep_for;

#include "../main.hpp"

void w8 (unsigned int secs)
{
	std::this_thread::sleep_for(std::chrono::seconds(secs));
}

Room windaParter (GameData& gameData)
{
	std::cout << "Jesteś na parterze, niedaleko windy." << std::endl
				<< "Słyszysz niepokojące odgłosy" << std::endl;

	for (int i=3; i>0; --i) {
		std::cout << "."; 
		std::cout.flush();
		w8(1);
	}

	std::cout << std::endl;
	std::cout << "TO WŚCIEKŁY ZAIONC!!!!!!!!!1" << std::endl;

	// nie pytajcie


	std::cout << "                                                                                               :osyd" << std::endl;
	std::cout << "                                                                                            :+o+:::+" << std::endl;
	std::cout << "                                                                                         .:+/+++/:+." << std::endl;
	std::cout << "                                                                                      `-/////::::/+ " << std::endl;
	std::cout << "                                                                                    .:+++/:::::::o` " << std::endl;
	std::cout << "                                                                                 `-/++//:::::::++`  " << std::endl;
	std::cout << "                                                                               `-+o+///::::::/+:    " << std::endl;
	std::cout << "                                                                             `-+o++///:::::+o/`     " << std::endl;
	std::cout << "                                                                           .:+++///:::::/oo:`       " << std::endl;
	std::cout << "                                                                         ./+o+///:::::+o+-`         " << std::endl;
	std::cout << "                                                                       -++o++////::/++:.            " << std::endl;
	std::cout << "    ```.................```                                ```+o+//:./o+oo+///:////-.               " << std::endl;
	std::cout << "/+++/////+++++++++++++++++++//::::::--...```             :++/:+oo/://ooyo+::////.`                  " << std::endl;
	std::cout << "yo::::://///:::::::://///////++++++++oooo+++++//:-.....://+oo/::/:+/o:+oo+/:-.                      " << std::endl;
	std::cout << "`:o++/::::::::::::::::::::::::::::////////+++++++oooo++o+//:::::/:/:/://so`                         " << std::endl;
	std::cout << "   .-/+o+++///:::::::::::::::::::::://////////+++ooos+/:::::::::::::::::///-                        " << std::endl;
	std::cout << "        .--:/++oo+//////::::::::::::://:::://+ooosssy+/::::::::::::://::::+o+-                      " << std::endl;
	std::cout << "                `.-:::-://////////::--...````      `ho/::/ossso+/::/+o::/hho:s-`--                  " << std::endl;
	std::cout << "                                              .//:.++/:::/++ohhhyyo+ssosdhys:/h//y                  " << std::endl;
	std::cout << "                                           ```:s//+//::::::/+osyyys+:///sss+::s::s-:`               " << std::endl;
	std::cout << "                                           +sso+/:::::::::://+++o:.-++++.-:::--::++/.               " << std::endl;
	std::cout << "                                          `-:+o/::::---..-----:-...-.+:.-.--.....:/:-`              " << std::endl;
	std::cout << "                                         :s+/::--......:s//ho:+/:--../-///-.........-+o`            " << std::endl;
	std::cout << "                            -          .`-yy/-........oddmmdmmmm/--::-.-.:-......./-:/+.            " << std::endl;
	std::cout << "                       `... :... .` `.`-/++/-.:--:.--+ssosydhddms:./::/:.:---.....-+`               " << std::endl;
	std::cout << "                       ...` :  .`.` `- y/:/+/-:--:./.s+sooosssyysyo:+/:-.:::....-:/+o               " << std::endl;
	std::cout << "                       .`.- -  .`..`.. :+/-sy/o+:-.:-+:o//-.:-...-:.----.--.-...-:``                " << std::endl;
	std::cout << "                        `                `+s+++o--............................:++oo/.               " << std::endl;
	std::cout << "                                        .o+os++o///---......................//:/+++///:             " << std::endl;
	std::cout << "                                       .o++o++++++o//----........-:/........:/    ./+//o.           " << std::endl;
	std::cout << "                                      `o++s++ooo++/-----..........-.......:./:      `/+:+:          " << std::endl;
	std::cout << "                                      ++++s++s+///-----.................../.+.        :+:+:         " << std::endl;
	std::cout << "                                  `/:-o+++s//s/:::../--.................:-:-o`     -/+os::o:        " << std::endl;
	std::cout << "                                /:/+oy++++s+/+o/:-..::::-.............../..-s.   `+++/:::::/+:`     " << std::endl;
	std::cout << "                               -s+o+oy++++oso+/+o///:--/:--..--:::::/+++//++s+++oooooo+:::::sos     " << std::endl;
	std::cout << "                             `-+ysosyhso+++osy+//+osyo+ooossooooooooo++++oooooosooooysy/ooo+yoo`    " << std::endl;
	std::cout << "                            :yhhyyyyyyyhyooooy+//++hyoooo+ooooooooooooo++//+oo......:oo++:::.       " << std::endl;
	std::cout << "                           +dhddhyyyyyyyho+++oysooy++o//s/o//:-----.......-::s`      ``             " << std::endl;
	std::cout << "                           :h:shdhyyyyyyyhsssssssso++s///:................:::+:                     " << std::endl;
	std::cout << "                            /s:shdyyyyyyyhdooo+//----....................:::::+                     " << std::endl;
	std::cout << "                             oyshdmhdddmdyo+++++/:------:::::::-........::::::s                     " << std::endl;
	std::cout << "                              oddmmyyyyhs++++++++/-:/++/:------/o/--..-::::::+o                     " << std::endl;
	std::cout << "                               .:ddyyyyyyys++++++o/-.           `-/////////+sy::::--.``             " << std::endl;
	std::cout << "                                :dhyyyyyyyyyysos:`                 .+o++++/+/::::::/+///:-.`        " << std::endl;
	std::cout << "                                ydyyyyyyyyyyyyhyo/-.``               -:/+oo++///////+o//+oyy/       " << std::endl;
	std::cout << "                               +dyyyyyyyyyyyyyyy+:::-+`                   `.-::::---::/:::::.       " << std::endl;
	std::cout << "                              :dyyyyyyyyyyyyys+:-----`                                              "	<< std::endl;






	gameData.zaionc = true;
	gameData.alive = false;
	return FAIL; 
}

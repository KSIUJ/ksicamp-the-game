#include <iostream>

#include "../main.hpp"

Room wc (__attribute__((unused)) GameData& gameData)
{

std::cout << std::endl;

 std::cout << " .************************************ " << std::endl; wait_ms(200);
 std::cout << " *###################################, " << std::endl; wait_ms(200);
 std::cout << " *###################################, " << std::endl; wait_ms(200);
 std::cout << " *###################################, " << std::endl; wait_ms(200);
 std::cout << " *####  ####    ###,  ##/        ####, " << std::endl; wait_ms(200);
 std::cout << " *####   ##/    (##   #   #####   ###, " << std::endl; wait_ms(200);
 std::cout << " *#####  ##  #,  ##  ##   ###########, " << std::endl; wait_ms(200);
 std::cout << " *#####   ,  ##  (   ##   ###########, " << std::endl; wait_ms(200);
 std::cout << " *######    ####    ###   #####   ###, " << std::endl; wait_ms(200);
 std::cout << " *######    ####    ####.        ####, " << std::endl; wait_ms(200);
 std::cout << " *###################################, " << std::endl; wait_ms(200);
 std::cout << " *###################################, " << std::endl; wait_ms(200);
 std::cout << " *###################################, " << std::endl; wait_ms(200);
 std::cout << " *#################################### " << std::endl; wait_ms(200);

std::cout << std::endl << std::endl;

	std::cout << "Wchodzisz do WC. " << std::endl;
	wait_s(1);
	std::cout << std::endl;
	std::cout << "Kontemplujesz przez moment swoje odbicie w lustrze. " << std::endl;
	wait_s(2);
	std::cout << "Twój wzrok podąża jednak niżej. Coś tutaj jest nie tak..." << std::endl;
	wait_s(2);
	std::cout << "Serce zaczyna Ci łomotać w piersi, a szeleszcząca w rurach woda zdecydowanie nie zwiastuje niczego dobrego..." << std::endl;
	wait_s(3);
	std::cout << std::endl;

	std::cout << "Czy chcesz zobaczyć co znajduje się w umywalce?" << std::endl;
	wait_s(1);

	if (yes())
	{
		std::cout << "To... "; 
		wait_s(1);
		std::cout << "N";wait_ms(100);std::cout<<"I";wait_ms(100);std::cout<<"E";wait_ms(100);std::cout<<"U";wait_ms(100);std::cout<<"M";wait_ms(100);std::cout<<"Y";wait_ms(100);std::cout<<"T";wait_ms(100);std::cout<<"E";wait_ms(100);std::cout<<" K";wait_ms(100);std::cout<<"U";wait_ms(100);std::cout<<"B";wait_ms(100);std::cout<<"K";wait_ms(100);std::cout<<"I";wait_ms(50);std::cout<<"!";wait_ms(50);std::cout<<"!";wait_ms(50);std::cout<<"!";

		wait_s(2);

		std::cout << std::endl << std::endl << "Ciąg dalszy nastąpi xD Tymczasem na korytarzu... ";
		wait_s(2);
		std::cout << std::endl;
	}
	else
	{
		std::cout << "Uciekasz z krzykiem. " << std::endl;
		wait_s(1);
		return KORYTARZ;
	}


	return KORYTARZ; 
}

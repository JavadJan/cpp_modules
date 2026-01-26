#include <iostream>

namespace{
	
}

void user_in()
{
	std::string name;
	int age;

	std::cout << "what is your age: ";
	std::cin >> age;

	std::cout << "was is dein name?: " ;
	std::getline(std::cin >> std::ws, name);
	//std::cin >> name;

	std::cout << name << " khare\n" ;
	std::cout << "you are " << age << " years old\n";

}
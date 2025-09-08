#include "Zombie.hpp"

Zombie::~Zombie()
{
	std::cout << "\033[1;31m" << this->name << ": destroyed 🧟🏳️" << "\033[0m" << std::endl;
}

Zombie::Zombie() : name("")
{
}

Zombie::Zombie(std::string name)
{
	this->name = name;
	std::cout << "\033[1;30m" << this->name << ": contructor called 🧟" << "\033[0m" << std::endl;
}
// Zombie::Zombie(std::string name) : name(name) {} //with list ininzializer

void	Zombie::announce()
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ...\n" ;
}


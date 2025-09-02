#include "Zombie.hpp"

Zombie::Zombie() 
{
	
}

Zombie::~Zombie()
{

}

std::string Zombie::getName()
{
	return this->name;
}

void Zombie::setName(std::string name)
{
	this->name = name;
}

void	Zombie::announce()
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ...\n" ;
}
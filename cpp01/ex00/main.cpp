#include "Zombie.hpp"
	
Zombie* newZombie( std::string name);
void randomChump( std::string name );

int main()
{
	Zombie *z = newZombie("foo");
	randomChump("javad");
	z->announce();
	delete(z);
	return (0);
}
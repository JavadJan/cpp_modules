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

/* GOAL: Heap vs Stack memory

	1. newZombie alloc memory in heap
	2. alloc memory in stakc, after return function the zombie destroy
*/
#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );
int main()
{
	Zombie *z = zombieHorde(10, "foo");
	for (int i = 0; i < 10; i++)
	{
		z[i].announce();
	}
	delete [] z;
	return (0);
}

/*	GOAL: alloc memory n number block in heap 
	1. delete the memory
	2. I used here the set
	3. integer to string 
		std::ostringtream s; writes into a std::string (instead of writing to stdout like std::cout
		s << int(var); std::cout << i;
		s.str() e.g., "42" // return the buffer as a string

	Zombie *zom = new Zombie[N]; // call constructor and init them
*/
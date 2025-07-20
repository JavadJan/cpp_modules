#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *zom = new Zombie[N];
	for (size_t i = 0; i < N; i++)
	{
		zom[i].setName(name + std::to_string(i));
	}
	return (zom);
}
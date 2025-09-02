#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *zom = new Zombie[N];

	for (int i = 0; i < N; i++)
	{
		std::ostringstream oss;
		oss << i;
		zom[i].setName(name + oss.str());
	}
	return (zom);
}
#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );
int main()
{
	Zombie *z = zombieHorde(10, "foo");
	for (size_t i = 0; i < 10; i++)
	{
		z[i].announce();
	}
	delete [] z;
	return (0);
}
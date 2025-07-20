#include "Harl.hpp"

int main(int ac, char **av)
{
	if (!(ac < 3 && ac > 1))
	{
		std::cout << "Invalid argument\n";
		return (1);
	}
	Harl harl;
	harl.complain(av[1]);
	return (0);
}
#include <iostream>

int main(int ac, char **av)
{
	int i = 1;

	if (ac < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		while (av[i])
		{
			for (size_t j = 0; av[i][j]; j++)
			{
				std::cout << (char)toupper(av[i][j]) ;
			}
			i++;
		}
		std::cout << std::endl;
	}
	return (0);
}

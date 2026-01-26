#include "../include/BitcoinExchange.hpp"
#include <unistd.h>
#include <list>
#include <fstream>

int	main(int ac, char *av[])
{
		
	try
	{
		if (ac != 2 || av[1] == NULL || av[1][0] == '\0')
			throw std::runtime_error("Error: could not open file.\n");
		
		std::string name = "./db/";
		name +=av[1];
		//std::cout << "path: " << name << std::endl;
		
		BitcoinExchange b(name.c_str());
		//std::cout << "path: " << name << std::endl;
		//std::cout << std::fixed << std::setprecision(2);

		b.print();
		//b.printDB();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}
	
	return (0);
}

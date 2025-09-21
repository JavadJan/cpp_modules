#include "test.hpp"

void fill_array()
{
	std::string foods[5];
	std::string temp;
	int len = sizeof(foods) / sizeof(foods[0]);

	for (int i = 0; i < len; i++)
	{
		std::cout << "input your foods that you like or 'q' to quit #" << i + 1 << ":" ; 
		std::getline(std::cin, temp);
		if (temp == "q")
		{
			break;
		}
		else{
			foods[i] = temp;
		}
	}
	std::cout << "listed the foods that you liked!\n";
	for (int j = 0; !foods[j].empty(); j++)
	{
		std::cout << foods[j] << std::endl ;
	}
	
}
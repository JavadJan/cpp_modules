#include <iostream>
#include "../include/Serializer.hpp"
#include <limits>  // for std::numeric_limits
#include <stdio.h>

int main(int ac, char *argv[])
{

	//double d = atof(litera.c_str());
	//std::cout << argv[1] << std::endl;
	//{
		//	ScalarConverter::convert(argv[1]);
		//}
		
	if (ac != 2) {

		std::cout << "Usage: ./convert <literal>" << std::endl;
		return 1;
	}
	std::string s = argv[1];
	if (s.size() == 0)
	{
		std::cout << "Literal is empty" << std::endl;
		return 1;
	}
	
    Serializer::convert(argv[1]);
    return 0;
}
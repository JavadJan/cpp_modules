#include <iostream>
#include "../include/ScalarConverter.hpp"
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
	//std::cout<< "\n\n" << argv[1] << " " << atof(s.c_str())<< std::endl << std::endl;
	//char* endptr;
    //errno = 0;
	//if (s[s.length() - 1] == 'f' || s[s.length() - 1] == 'F')
	//	s = s.substr(0, s.length() - 1).c_str();
	//float f = std::strtold(s.c_str(), &endptr);
	//if (*endptr != '\0' || errno == ERANGE)
	//{
	//	std::cout << "INvalid arg: " << f << std::endl;
	//	return 1;
	//}
	//std::string s = argv[1];
	//double d = atof(s.substr(0, s.size()).c_str());

	//int tt = -1 && 0;
	//std::string::npos;
	//std::cout <<"double: " << d << std::endl;
	//std::cout <<"Integer: " << static_cast<int>(d) << std::endl;
	//std::cout <<"float: " << static_cast<float>(d) << std::endl;
	//std::cout << "\n\n\n";
    ScalarConverter::convert(static_cast<std::string>(argv[1]));
    return 0;
}

/*./convert -1.7976931348623158e+308f

	it is float
	base in float: -inf 22
	char: impossible
	int: impossible
	float: -inff ---------> first convert to -inf float
	double: -inf ---------> then -inf convert to double

	------------------------------------------------------------
	./convert +1.7976931348623158e+308f

	it is float
	base in float: inf 22
	char: impossible
	int: impossible
	float: +inff ----------> first convert to +int float
	double: +inf ----------> then convert to +int float

*/
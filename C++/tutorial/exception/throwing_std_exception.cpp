#include <iostream>

int main()
{
	try
	{
		std::string s = "hi";
		if (s.size() < 5)
			throw std::length_error("String too short");
		std::cout << s << std::endl;
	}
	catch(const std::length_error& e)
	{
		std::cerr << e.what() << '\n';
	}
	catch(const std::exception& e)
	{
		std::cout << "unknown lenght: " << e.what() << std::endl;
	}
	
}
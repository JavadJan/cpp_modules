#include <iostream>

int main()
{
	try
	{
		int a = -5;
		if (a < 0)
			throw std::invalid_argument("Too low of grade");
		if (a > 10)
			throw std::out_of_range("Too High of grade");
	}
	catch(const std::out_of_range& e)
	{
		std::cout << "Higher than grade: " << e.what() << '\n';
	}
	catch(const std::invalid_argument &invalid)
	{
		std::cout << "Lower than grade: " << invalid.what() << std::endl;
	}
}
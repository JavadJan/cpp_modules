#include <iostream>

int main()
{
	try
	{
		int a = 10;
		int b = 0;

		if (b==0)
			throw "Dvision by zero not allowed!";
		std::cout << a / b << std::endl;

	}
	catch(const char *msg)
	{
		std::cerr << msg << '\n';
	}
	
}
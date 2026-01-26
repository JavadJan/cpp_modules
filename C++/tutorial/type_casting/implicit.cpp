#include <iostream>

int main()
{
	int a = 10;
	char A = 'A';

	int c = a + A ;
	std::cout << c << std::endl;
	char b = a + A; // 75 == 'K'
	std::cout << b << std::endl;

	(unsigned int )a;
	std::cout << a << ", " << (float)a << ", double " << (double)a <<  std::endl;
}
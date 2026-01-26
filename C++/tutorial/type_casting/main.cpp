#include <iostream>
#include <iomanip>

int main()
{
	std::cout << "char: " << sizeof(char) << std::endl;
	std::cout << "int: " << sizeof(int) << std::endl;
	std::cout << "float: " << sizeof(float) << std::endl;
	std::cout << "double: " << sizeof(double) << std::endl;
	std::cout << "size_t: " << sizeof(size_t) << std::endl;
	std::cout << "unsigned: " << sizeof(unsigned) << std::endl;
	std::cout << "long: " << sizeof(long) << std::endl;


	int a = 3;
	int b = 2;
	std::cout << "a / b: " << a/b << std::endl;
	std::cout << "(float)a / b: " << (float)a/b << std::endl;
	std::cout << "(float)a / b: " << static_cast<float>(a)/b << std::endl;

	float f= 10.5;
	int i;
	i = f;
	i = static_cast<int>(f); // it is better to convert to explicitly

	char c = 'c';
	int x = 90;
	c = x; // on denger 4 byte to 1 byte

	std::cout << "\n\n";
	int j = 10;
	std::cout << std::fixed << std::setprecision(2) << static_cast<float> (j) << "f" << "\n";

}
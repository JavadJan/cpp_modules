#include "../include/Iter.hpp"

int main()
{
	std::cout << "\033[1;33m[TEST1: ] -----Array of Integer -----\033[0m" << std::endl;
	int arr[3] = {10, 11, 9};
	Iter(arr, 3, func<int>);
	
	std::cout << "\033[1;33m[TEST2: ] -----Array of string -----\033[0m" << std::endl;
	const char *str[3] = {"Javad", "John", "Alex"};
	Iter(str, 3, func<const char *>);
	
	std::cout << "\033[1;33m[TEST3: ] -----Array of float -----\033[0m" << std::endl;
	float f[3] = {10.10f, 11.11f, 9.9f};
	Iter(f, 3, func<float>);
	
	std::cout << "\033[1;33m[TEST4: ] -----Array of double -----\033[0m" << std::endl;
	double d[3] = {10.10, 11.11, 9.9};
	Iter(d, 3, func<double>);
}


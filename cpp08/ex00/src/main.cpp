#include "../include/Easyfind.hpp"

//using functions::swap;
//using functions::min;
//using functions::max;


int main( void ) 
{
	try
	{
		std::vector<int> v = {1, 2, 3};
		//std::list<int> l = {4, 5, 6};
		//std::array<int, 3> a = {7, 8, 9};
		std::cout << *easyfind<std::vector<int>>(v, 2) << std::endl;
		std::cout << *easyfind<std::vector<int>>(v, 5) << std::endl;

		//std::list<int> y = easyfind(l, 2);
		//std::cout << y[0] << std::endl;

		//std::array<int> z = easyfind(a, 1);
		//std::cout << z << std::endl;
		//std::list<int>::iterator;
	
	}
	catch(const MyException& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}

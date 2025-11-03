#ifndef Iter_hpp
# define Iter_hpp

#include <iostream>

/* 
	The first parameter is the address of an array.
	The second one is the length of the array, passed as a const value.
	The third one is a function that will be called on every element of the array.
*/

template <typename T>
void func(T x)
{
	std::cout << "value " << x << std::endl;
}

template <typename T0, typename F>
void Iter(T0 *array, const size_t length,  F function)
{
	(void)function;
	for (size_t i = 0; i < length; i++)
	{
		function(array[i]);
		//std::cout << addr[i] << std::endl;
	}
}	

#endif

#include "Fixed.hpp"

int	main(void)
{
	Fixed a;
	Fixed const b(10);
	Fixed const c(42.42f);
	Fixed const d(b);
	a = Fixed(1234.4321f);
	// a is user defined data type, it need overload << 
	std::cout << "a is " << a << std::endl; // a is an object
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl; // << c -> operator (std::cout , c); retutn a printabl ostream
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	return (0);
}

//a.operator+(b);
/* operator (std::cout , c); it should return an std::ostream */
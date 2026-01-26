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

// a.operator+(b);
/* operator (std::cout , c); it should return an std::ostream */

/*
	when I call std::cout << 5; in fact I am calling the overload for int
	std::ostream& operator<<(std::ostream& out, int value);

	// stream: flow of data from input to output
	std::cout << "hello" => I am saying take the string and push it into cout then
	cout prints it int terminal

	include <iostream> input/output stream, lead data to output with conveyor belt
	characters one-by-one from program to the screan

	<< is a binary operator, and it always take two parameter, the things on the left and the right
	left: ostream
	right: value
	then compiler convert it to a function call

	// So when the left side is an int, << means bit shift.
	// When the left side is an ostream, << means send into the stream.


*/	
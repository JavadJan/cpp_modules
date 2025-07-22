#include "Fixed.hpp"

const int Fixed::fractional = 8;

Fixed::Fixed():fixed_point(0){
	std::cout << "Default constructor called\n";
}
Fixed::~Fixed(){
	std::cout << "Destructor called\n";
}

Fixed::Fixed(const Fixed& other)
{
	//this->fixed_point = other.fixed_point;
	std::cout << "Copy constructor called\n";
	*this = other;
}

Fixed& Fixed::operator= (const Fixed& other)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &other)
	{
		this->fixed_point = other.getRawBits();
	}
	return (*this);
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return (this->fixed_point);

}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called\n";
	this->fixed_point = raw;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhavari <mkhavari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:39:20 by mkhavari          #+#    #+#             */
/*   Updated: 2025/09/22 17:39:21 by mkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fractional = 8;

Fixed::Fixed():fixed_point(0){
	//std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int x):fixed_point(0){
	//std::cout << "Int constructor called\n";
	this->fixed_point = x << this->fractional; // input * 256 == input * (2 ^ 8)
}

Fixed::Fixed(const float f):fixed_point(0){
	//std::cout << "Float constructor called\n";
	// float can not be shifted e.g., round diese (5 * ( 2 ^ 8)) auf
	this->fixed_point = roundf(f * (1 << this->fractional));
	// std::cout << "Fixed Float Constructor called: " << this->fixed_point << std::endl;

}

Fixed::~Fixed(){
	//std::cout << "Destructor called\n";
}

Fixed::Fixed(const Fixed& other)
{
	//this->fixed_point = other.fixed_point;
	//std::cout << "Copy constructor called\n";
	*this = other;
}

Fixed& Fixed::operator= (const Fixed& other)
{
	//std::cout << "Copy assignment operator called\n";
	if (this != &other)
	{
		this->fixed_point = other.getRawBits();
	}
	return (*this);
}

int Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member function called\n";
	return (this->fixed_point);

}

void Fixed::setRawBits(int const raw)
{
	//std::cout << "setRawBits member function called\n";
	this->fixed_point = raw;
}

float Fixed::toFloat(void) const
{
	// this devide the float e.g 1 << 8 == 256
	return ((float)this->fixed_point / (float)(1 << this->fractional));
}

int Fixed::toInt(void) const
{
	return (this->fixed_point >> this->fractional);
}

std::ostream    &operator<<(std::ostream &out, Fixed const &fixed)
{
	out << fixed.toFloat();
	//Send the result of fixed.toFloat() to the output stream out
	return (out);
}



/* overloead: (obj /-+* obj)  */
//Fixed(42) + Fixed(43)
//Fixed(42.42) + Fixed(43.45)
Fixed Fixed::operator*(const Fixed &other) const
{
	// convert to fixed_point
	return Fixed(this->toFloat() * other.toFloat());
}
Fixed Fixed::operator+(const Fixed &other) const
{
	return Fixed(this->toFloat() * other.toFloat());
}
Fixed Fixed::operator-(const Fixed &other) const
{
	return Fixed(this->toFloat() * other.toFloat());
}
Fixed Fixed::operator/(const Fixed &other) const
{
	return Fixed(this->toFloat() * other.toFloat());
}

/* < != > =< >= ==*/
bool Fixed::operator==(const Fixed& other) const
{
	if (this->toFloat() == other.toFloat())
		return true;
	else
		return false;
}
bool Fixed::operator>(const Fixed& other) const
{
	if (this->toFloat() > other.toFloat())
		return true;
	else
		return false;
}
bool Fixed::operator<(const Fixed& other) const
{
	if (this->toFloat() < other.toFloat())
		return true;
	else
		return false;
}
bool Fixed::operator>=(const Fixed& other) const
{
	if (this->toFloat() >= other.toFloat())
		return true;
	else
		return false;
}
bool Fixed::operator<=(const Fixed& other) const
{
	if (this->toFloat() <= other.toFloat())
		return true;
	else
		return false;
}
bool Fixed::operator!=(const Fixed& other) const
{
	if (this->toFloat() != other.toFloat())
		return true;
	else
		return false;
}

// modify the obj and return itself like ++a
Fixed& Fixed::operator++() // return itself, it refer to itself
{
	this->fixed_point++;
	return (*this);
}
Fixed& Fixed::operator--() // return itself, it refer to itself
{
	this->fixed_point--;
	return (*this);
}
Fixed Fixed::operator++(int) // return itself, it refer to itself
{
	Fixed temp = *this;
	this->fixed_point++;
	return (temp);
}
Fixed Fixed::operator--(int) // return itself, it refer to itself
{
	Fixed temp = *this;
	this->fixed_point--;
	return (temp);
}

/* max, min */
const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return (a);
	else 
		return (b);
}
const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a < b)
		return (a);
	else 
		return (b);
}
Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return (a);
	else 
		return (b);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return (a);
	else 
		return (b);
}
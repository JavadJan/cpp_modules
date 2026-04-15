/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhavari <mkhavari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:20:17 by mkhavari          #+#    #+#             */
/*   Updated: 2025/09/22 18:26:57 by mkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fractional = 8;

Fixed::Fixed():fixed_point(0){
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int x):fixed_point(0){
	std::cout << "Int constructor called\n";
	this->fixed_point = x << this->fractional; // 3 * 256 == input * (2 ^ 8)
}

Fixed::Fixed(const float f):fixed_point(0){
	std::cout << "Float constructor called\n";
	// float can not be shifted e.g., round diese (5 * ( 2 ^ 8)) auf
	this->fixed_point = roundf(f * (1 << this->fractional));
}

Fixed::~Fixed(){
	std::cout << "Destructor called\n";
}

Fixed::Fixed(const Fixed& other)
{
	//this->fixed_point = other.fixed_point;
	std::cout << "Copy constructor called\n";
	*this = other; // here I used assigned constructor
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

float Fixed::toFloat(void) const
{
	// this devide the float e.g 
	return ((float)this->fixed_point / (float)(1 << this->fractional));
}

int Fixed::toInt(void) const
{
	return (this->fixed_point >> this->fractional); // 42.42 == this->fixed / 256
}

std::ostream    &operator<<(std::ostream &out, Fixed const &fixed)
{
	//* std::cout << 5; send int to the stream
	// std::ostream &operator<<(std::ostream &o, int value);
	// 
	out << fixed.toFloat();
	//Send the result of fixed.toFloat() to the output stream out
	return (out);
}

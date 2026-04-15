/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhavari <mkhavari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:20:17 by mkhavari          #+#    #+#             */
/*   Updated: 2026/04/15 21:14:07 by mkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point():x(0.0f), y(0.0f)
{
	//std::cout << "\033[1;31mDefault constructor of point called, init x AND y to zero\033[0m" << std::endl;
}
Point::~Point()
{
	//std::cout << "\033[1;32mDestructor of point called,\033[0m" << std::endl;
}

Point::Point(const float xx, const float yy): x(xx), y(yy) // uses Fixed(float f) construcor
{
	//std::cout << "\033[1;31mConstructor with two parameter called\33[0m" << std::endl;
}
/* copy assignment constructor */
Point& Point::operator=(const Point& other)
{
	//std::cout << "\033[1;34mCopy assign constructor of point called,\033[0m" << std::endl;
	if (this == &other) // becaus the attribute is const we can not assign it
		return (*this);
	return (*this);
}
/* copy constructor */
Point::Point(const Point& other):x(other.getX()), y(other.getY())
{
	//std::cout << "\033[1;35mCopy constructor of point called,\033[0m" << std::endl;
	//*this = other;
}
const Fixed& Point::getX() const  { return this->x; } // read only
const Fixed& Point::getY() const { return this->y; }

std::ostream &operator<<(std::ostream &cout, Point const &point)
{
	cout << "x: " << point.getX() << " y: " << point.getY(); // when we have to attribute to overload
	return (cout);
}

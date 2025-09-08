#include "Point.hpp"

Point::Point():x(0), y(0)
{
	std::cout << "\033[1;31mDefault constructor of point called, init x AND y to zero\033[0m" << std::endl;
}
Point::~Point()
{
	
}

Point::Point(const int xx, const int yy): x(xx), y(yy)
{

}
/* copy assignment constructor */
Point& Point::operator=(const Point& other)
{
	if (this == &other)
		return (*this);
	return (*this);
}
/* copy constructor */
Point::Point(const Point& other):x(other.x), y(other.y)
{
	//*this = other;
}




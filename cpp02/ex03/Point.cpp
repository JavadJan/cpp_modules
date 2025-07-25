#include "Point.hpp"

Point::Point():x(0), y(0)
{

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




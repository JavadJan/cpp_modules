#ifndef POINT_HPP
#define POINT_HPP

class Point
{
	private:
		const int x; // it is const init in initializer
		const int y;
	Point();
	Point(const int xx, const int yy);
	~Point();
	Point(const Point& other);
	Point& operator=(const Point& other);
	
};

#endif
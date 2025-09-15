#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <cmath>

class	Fixed
{
	private:
		int fixed_point;
		static const int fractional;
	public:
		Fixed();
		Fixed(const float f);
		Fixed(const int n);
		~Fixed();
		Fixed(const Fixed& other); // copy constructor
		Fixed& operator = (const Fixed& other); //asignment constructor
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
};	

// this one is not member function
std::ostream    &operator<<(std::ostream &o, Fixed const &fixed);

#endif

/* I could not operator << as public function, becaise LHS is not Fixed object

	Use a member function when the left-hand side (LHS) is the class itself.
	Use a non-member (possibly friend) function when the LHS is not your class.

	Fixed operator+(const Fixed& other) const;  // LHS: Fixed, RHS: Fixed

	Fixed a, b;
	Fixed c = a + b;
	a.operator+(b);
*/
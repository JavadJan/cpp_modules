#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class	Fixed
{
	private:
		int fixed_point;
		static const int fractional; // it can be 100 or 1000 but here is 10^8
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed& other); // copy constructor
		Fixed& operator = (const Fixed& other); //asignment constructor
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};		

#endif
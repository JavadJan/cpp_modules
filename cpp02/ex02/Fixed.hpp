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
		//Fixed(Fixed& operator*(const Fixed& other));
		~Fixed();
		Fixed(const Fixed& other); // copy constructor
		// return a refrence to the current object.
		Fixed& operator = (const Fixed& other); //asignment constructor
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
		/* add overload operator */
		/* (obj /+-* obj) */
		Fixed operator*(const Fixed& other) const;
		Fixed operator+(const Fixed& other) const;
		Fixed operator-(const Fixed& other) const;
		Fixed operator/(const Fixed& other) const;

		/* < != > =< >= ==*/
		bool operator==(const Fixed& other) const;
		bool operator>(const Fixed& other) const;
		bool operator>=(const Fixed& other) const;
		bool operator<=(const Fixed& other) const;
		bool operator!=(const Fixed& other) const;
		bool operator<(const Fixed& other) const;

		/* --int/int++ and ++int/int++ */
    	Fixed& operator++();     // ++a 
    	Fixed operator++(int);   // a++
    	Fixed& operator--();     // --a
		Fixed operator--(int);   // a--

		/* max, min,  */ 
		static const Fixed& max(const Fixed& a, const Fixed& b);
		static Fixed& max(Fixed& a, Fixed& b);
		static Fixed& min(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed& a, const Fixed& b);
		
};	

std::ostream    &operator<<(std::ostream &o, Fixed const &fixed);

#endif
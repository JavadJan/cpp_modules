/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhavari <mkhavari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:16:05 by mkhavari          #+#    #+#             */
/*   Updated: 2025/09/22 15:16:10 by mkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
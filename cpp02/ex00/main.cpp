/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhavari <mkhavari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:16:12 by mkhavari          #+#    #+#             */
/*   Updated: 2025/09/22 18:22:37 by mkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {

	Fixed a;
	Fixed b( a );
	Fixed c;
	// Here, a = b; invokes a.operator=(b)
	// Enable Chained Assignment
	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return 0;
}

/* 
	A fixed-point number is a way to represent real number using integer. 
	// fractional point is 8 bit=> num * 256 or num << 8
	// devide to return it back: num / 256 or num >> 8 bits
*/
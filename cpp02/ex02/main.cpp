/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhavari <mkhavari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:20:17 by mkhavari          #+#    #+#             */
/*   Updated: 2026/04/15 21:13:38 by mkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"

int	main(void)
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	std::cout << a << std::endl;
	std::cout << ++a << std::endl; // 1 / 256
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;
	
	// std::cout << "-------------------\n";
	// Fixed b0(Fixed(5.05f) * Fixed(2));
	// Fixed c; // without const
	// Fixed const c0; // without const
	// std::cout << Fixed::max(a, b0) << std::endl;
	// std::cout << Fixed::max(c0, b0) << std::endl;
	// std::cout << Fixed::max(c0, b) << std::endl;

	// std::cout << "---------------------\n";

	return (0);
}
/* 
	
*/
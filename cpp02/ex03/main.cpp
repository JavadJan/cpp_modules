/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhavari <mkhavari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:38:55 by mkhavari          #+#    #+#             */
/*   Updated: 2025/09/22 17:38:57 by mkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

int main() {
    	
	Point a(0,0);
	Point b(4,0);
	Point c(1,3);
	Point point(1,1);
    std::cout << "pointA: (" << a.getX() << ", " << a.getY() << ")\n";
    std::cout << "pointB: (" << b.getX() << ", " << b.getY() << ")\n";
    std::cout << "pointC: (" << c.getX() << ", " << c.getY() << ")\n";
    std::cout << "point: (" << point.getX() << ", " << point.getY() << ")\n";
	if (bsp(a, b, c, point))
		std::cout << "Point is inside traingle" << std::endl;
	else
		std::cout << "Point is outsied traingle" << std::endl;

	Point a1(0,0);
	Point b1(4,0);
	Point c1(1,3);
	Point point1(5,1);
	std::cout << "pointA1: (" << a1.getX() << ", " << a1.getY() << ")\n";
    std::cout << "pointB1: (" << b1.getX() << ", " << b1.getY() << ")\n";
    std::cout << "pointC1: (" << c1.getX() << ", " << c1.getY() << ")\n";
    std::cout << "point1: (" << point1.getX() << ", " << point1.getY() << ")\n";
	if (bsp(a1, b1, c1, point1))
		std::cout << "Point is inside traingle" << std::endl;
	else
		std::cout << "Point is outsied traingle" << std::endl;
}
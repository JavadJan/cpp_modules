/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhavari <mkhavari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:20:17 by mkhavari          #+#    #+#             */
/*   Updated: 2026/04/15 21:14:16 by mkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP
#include <iostream>
#include "Fixed.hpp"

class	Point
{
	private:
		const Fixed x;
		const Fixed y;

	public:
		Point();
		Point(const float x, const float y);
		Point(const Point& copy);
		~Point();
		Point &operator=(const Point &src);
		const Fixed &getX(void)const;
		const Fixed &getY(void)const;

};

std::ostream	&operator<<(std::ostream &o, Point const point);
bool bsp( Point const a, Point const b, Point const c, Point const point);
#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhavari <mkhavari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:20:17 by mkhavari          #+#    #+#             */
/*   Updated: 2026/04/15 21:13:52 by mkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Point.hpp"

float cross(Point e0, Point e2)
{
	return (e0.getX().toFloat() * e2.getY().toFloat() - e0.getY().toFloat() * e2.getX().toFloat());
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Point ab((a.getX().toFloat()-b.getX().toFloat()), (a.getY().toFloat()-b.getY().toFloat()));
	Point ap((a.getX().toFloat()-point.getX().toFloat()), (a.getY().toFloat()-point.getY().toFloat()));

	float edgeAB = cross(ab, ap);

	Point bc((b.getX().toFloat()-c.getX().toFloat()), (b.getY().toFloat()-c.getY().toFloat())) ;
	Point bp((b.getX().toFloat()-point.getX().toFloat()), (b.getY().toFloat()-point.getY().toFloat()));
	float edgeBC = cross(bc, bp);

	Point ca((c.getX().toFloat()-a.getX().toFloat()), (c.getY().toFloat()-a.getY().toFloat())) ;
	Point cp((c.getX().toFloat()-point.getX().toFloat()), (c.getY().toFloat()-point.getY().toFloat()));
	float edgeCA = cross(ca, cp);
	
	if (edgeAB > 0 && edgeBC > 0 && edgeCA > 0)
		return true;
	else if (edgeAB < 0 && edgeBC < 0 && edgeCA < 0)
		return true;
	return false;
}
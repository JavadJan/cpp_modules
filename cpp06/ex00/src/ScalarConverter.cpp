/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhavari <mkhavari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 13:17:01 by mkhavari          #+#    #+#             */
/*   Updated: 2025/11/26 13:17:03 by mkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"
#include <cstdio>

ScalarConverter::ScalarConverter()
{
	// not nead to print any thing because it uninstncable
}
ScalarConverter::~ScalarConverter()
{
	// not nead to print any thing because it uninstncable
}
ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	// not nead to print any thing because it uninstncable
	(void)other;
}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	// not nead to print any thing because it uninstncable
	(void)other;
	return (*this);
}


void ScalarConverter::convert(const std::string &str)
{
	e_type	type;

	type = detectType(str, str.size());
	switch (type)
	{
	case SPECIAL:
	{
		Special(str);
		break;
	}
	case CHAR:
	{
		Char(str);
		break;
	}
	case INT:
	{
		Integer(str);
		break;
	}
	case FLOAT:
	{
		Float(str);
		break;
	}
	case DOUBLE:
	{
		Double(str);
		break;
	}	
	default:
	{
		//std::cout << "INVALID\n";
		Invalid(str);
		break;
	}
	}
}

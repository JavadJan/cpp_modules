/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhavari <mkhavari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 13:16:51 by mkhavari          #+#    #+#             */
/*   Updated: 2025/11/26 13:16:53 by mkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../include/ScalarConverter.hpp"
#include <limits>  // for std::numeric_limits
#include <stdio.h>

int main(int ac, char *argv[])
{

	//double d = atof(litera.c_str());
	//std::cout << argv[1] << std::endl;
	//{
		//	ScalarConverter::convert(argv[1]);
		//}
		
	if (ac != 2) {

		std::cout << "Usage: ./convert <literal>" << std::endl;
		return 1;
	}
	std::string s = argv[1];
	if (s.size() == 0)
	{
		std::cout << "Literal is empty" << std::endl;
		return 1;
	}
    ScalarConverter::convert(static_cast<std::string>(argv[1]));
    return 0;
}

/*./convert -1.7976931348623158e+308f

	it is float
	base in float: -inf 22
	char: impossible
	int: impossible
	float: -inff ---------> first convert to -inf float
	double: -inf ---------> then -inf convert to double

	------------------------------------------------------------
	./convert +1.7976931348623158e+308f

	it is float
	base in float: inf 22
	char: impossible
	int: impossible
	float: +inff ----------> first convert to +int float
	double: +inf ----------> then convert to +int float

*/
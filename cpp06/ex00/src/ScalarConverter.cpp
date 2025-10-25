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

/*
	I GET THE DOUBLE AS BASE, BECAUSE:
	double can hold any int or float value without losing much precision.
	It can represent NaN, inf,
		and other special floating-point values (which int and char cannot).
	It allows safe downcasting using static_cast<>().
*/


void ScalarConverter::convert(const std::string &str)
{
	e_type	type;

	type = detectType(str, str.size());
	// approach 1: with function pointer
		//int arr[] = {0, 1, 2, 3, 4, -1};
		//void (*map[6])(const std::string &) = { Special, Char, Integer, Float, Double, Invalid};
		//for (int i = 0; i < 6; i++)
		//{
		//	if (i== type)
		//	{
		//		map[i](str);
		//	}
		//}
	//approach 2: with switch case
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

/* first ask question?
	1. what kind of coversion operator exist?
	2. how to covert string to char?

*/
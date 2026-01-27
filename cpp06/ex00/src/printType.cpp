/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printType.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhavari <mkhavari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 13:16:58 by mkhavari          #+#    #+#             */
/*   Updated: 2025/11/26 13:16:59 by mkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"

void	Invalid(const std::string &s);
void	Char(const std::string &str);
void	Special(const std::string &str);
void	Integer(const std::string &str);
void	Float(const std::string &str);
void	Double(const std::string &str);

void	Special(const std::string &str)
{
	double	d;

	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	d = atof(str.substr(0, str.size()).c_str());
	std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}
void	Invalid(const std::string &str)
{
	std::cout << "Invalid Argument: " << str << std::endl;
}
void	Char(const std::string &str)
{
	char	c;

	c = static_cast<char>(str[0]);
	std::cout << "char :"
				<< "'" << c << "'" << std::endl;
	std::cout << "int :" << static_cast<int>(c) << std::endl;
	std::cout << "float :" << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double :" << static_cast<double>(c) << ".0" << std::endl;
}
void	Integer(const std::string &str)
{
	long	n;

	(void)str;
	// int n = std::atoi(str.c_str());
	n = std::atol(str.c_str());
	std::cout << "char: ";
	if (n < 0 || n > 127)
		std::cout << "impossible" << std::endl;
	else
	{
		if (isprint(n))
		{
			std::cout << "'" << static_cast<char>(n) << "'" << std::endl;
		}
		else
			std::cout << "Non-displayable" << std::endl;
	}
	std::cout << "int: ";
	if (n < MIN_INT || n > MAX_INT)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(n) << std::endl;

		// float
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(n) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(n) << std::endl;
}
void	Float(const std::string &str)
{
	float	f;
	long	n;

	f = atof(str.substr(0, str.size() - 1).c_str());
	size_t dot = str.find('.');

	size_t pos = str.find('.');
	size_t _pos = (pos == std::string::npos) ? 0 : str.length() - pos - 2;
	// std::cout << "_pos : " << _pos << std::endl;
	bool	tolerance = std::fabs(f - static_cast<int>(f)) < 0.0000000000001;
	// std::cout << "f : " << f << std::endl;
	// std::cout << "f : " << std::fixed << std::setprecision(10) << f << std::endl;
	// std::cout << "static_cast<int>(f)" << std::fixed << std::setprecision(10) << static_cast<int>(f) << std::endl;

	// std::cout << "tolerance: " << (std::fabs(f - static_cast<int>(f)) < 0.0000000000001) << std::endl;
	// std::cout << "-: " << (std::fabs(f - static_cast<int>(f))) << std::endl;
	n = static_cast<long>(f);
	std::cout << "char: ";
	if (n < 0 || n > 127)
		std::cout << "impossible" << std::endl;
	else
	{
		if (isprint(f))
			std::cout << "'" << static_cast<char>(n) << "'" << std::endl;
		else
			std::cout << "Non-displayable" << std::endl;
	}
	std::cout << "int: ";
	if (n < MIN_INT || n > MAX_INT)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(n) << std::endl;
	
	
	// std::cout << "float: " << _pos  << static_cast<float>(f) << "f" << std::endl;
	if (std::isnan(f))
		std::cout << "float: nanf" << std::endl;
	else if (std::isinf(f))
		std::cout << "float: " << (f > 0 ? "+inff" : "-inff") << std::endl;
	// else if (f < MIN_FLOAT || f > MAX_FLOAT)
	// 	std::cout << "float: impossible" << std::endl;
	else
	{

		if (_pos <= 7)
		{
			std::cout << std::fixed << std::setprecision(_pos);

		}
		else if (_pos > 7 && tolerance)
		{
			std::cout << std::fixed << std::setprecision(1);

		}
		std::cout << "float: " << static_cast<float>(f) << ((tolerance && dot ==std::string::npos) ? ".0f" : "f") << std::endl;
	}
	
	
	if (std::isnan(f))
		std::cout << "double: nan" << std::endl;
	else if (std::isinf(f))
		std::cout << "double: " << (f > 0 ? "+inf" : "-inf") << std::endl;
	else
	{
		std::cout << "double: " << static_cast<double>(f) << ((tolerance && dot ==std::string::npos) ? ".0" : "") << std::endl;
	}
}

void	Double(const std::string &str)
{
	double	f;
	long	n;
	//size_t tolerance = (pos == std::string::npos) ? 0 : str.length() - pos - 1; // one for f
	size_t pos = str.find('.');
	size_t _pos = (pos == std::string::npos) ? 0 : str.length() - pos - 1;

	f = atof(str.c_str());
	bool	tolerance = std::fabs(f - static_cast<int>(f)) < 0.0000000000001;
	n = static_cast<long>(f);

	/* CHAR */
	std::cout << "char: ";
	if (n < 0 || n > 127)
		std::cout << "impossible" << std::endl;
	else
	{
		if (isprint(n))
			std::cout << "'" << static_cast<char>(n) << "'" << std::endl;
		else
			std::cout << "Non-displayable" << std::endl;
	}
	/* INT */
	std::cout << "int: ";
	if (n < MIN_INT || n > MAX_INT)
		std::cout << "impossible" << std::endl;
	else
		std::cout << n << std::endl;
	/* FLOAT */
	if (std::isnan(static_cast<float>(f)))
		std::cout << "float: nanf" << std::endl;
	else if (std::isinf(static_cast<float>(f)))
		std::cout << "float: " << (f > 0 ? "+inff" : "-inff") << std::endl;
	else if (f < MIN_FLOAT || f > MAX_FLOAT)
		std::cout << "float: impossible" << std::endl;
	else
	{
		//std::cout << std::fixed << std::setprecision(tolerance);
		std::cout << "float: " << static_cast<float>(f) << (tolerance ? ".0f" : "f") << std::endl;
	}

	/* DOUBLE */
	if (std::isnan(f))
		std::cout << "double: nan" << std::endl;
	else if (std::isinf(f))
		std::cout << "double: " << (f > 0 ? "+inf" : "-inf") << std::endl;
	else
	{
		//std::cout << std::fixed << std::setprecision(tolerance);
		if (_pos <= 17)
		{
			std::cout << std::fixed << std::setprecision(_pos);
		}else if (_pos > 17 && tolerance)
		{
			std::cout << std::fixed << std::setprecision(1);

		}
		std::cout << "double: " << f << (tolerance ? ".0" : "") << std::endl;
	}
}

/* in scientific notation -3.40282e+38 means:
-3.40282 × 10^38 = -340,282,000,000,000,000,000,000,000,000,000,000,000
*/
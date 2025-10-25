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
	std::cout << "float: " << static_cast<float>(n) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(n) << ".0" << std::endl;
}
void	Float(const std::string &str)
{
	float	f;
	long	n;

	f = atof(str.substr(0, str.size() - 1).c_str());

	size_t pos = str.find('.');
	size_t _pos = (pos == std::string::npos) ? 0 : str.length() - pos - 2;
	bool	tolerance = std::fabs(f - static_cast<int>(f)) < 0.0000000000001;
	std::cout << "base in float: " << static_cast<float>(f) << " " << str.length() - pos - 1 << std::endl;
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
	
	if (std::isnan(f))
		std::cout << "float: nanf" << std::endl;
	else if (std::isinf(f))
		std::cout << "float: " << (f > 0 ? "+inff" : "-inff") << std::endl;
	else if (f < MIN_FLOAT || f > MAX_FLOAT)
		std::cout << "float: impossible" << std::endl;
	else
	{

		if (_pos <= 7)
			std::cout << std::fixed << std::setprecision(_pos);
		//std::cout << "float: " << static_cast<float>(f) << "f" << std::endl;
		std::cout << "float: " << f << (tolerance ? ".0f" : "f") << std::endl;;
	}
	
	
	if (std::isnan(f))
		std::cout << "double: nan" << std::endl;
	else if (std::isinf(f))
		std::cout << "double: " << (f > 0 ? "+inf" : "-inf") << std::endl;
	else
	{
		//std::cout << std::fixed << std::setprecision(tolerance);
		std::cout << "double: " << static_cast<double>(f) << (tolerance ? ".0" : "") << std::endl;
	}
}

void	Double(const std::string &str)
{
	double	f;
	long	n;
	size_t pos = str.find('.');
	//size_t tolerance = (pos == std::string::npos) ? 0 : str.length() - pos - 1; // one for f
	
	f = atof(str.c_str());
	std::cout << "base in double: " << static_cast<float>(f) << " " << str.length() - pos - 1 << std::endl;
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
		std::cout << "float: " << static_cast<float>(f) << "f" << std::endl;
	}

	/* DOUBLE */
	if (std::isnan(f))
		std::cout << "double: nan" << std::endl;
	else if (std::isinf(f))
		std::cout << "double: " << (f > 0 ? "+inf" : "-inf") << std::endl;
	else
	{
		//std::cout << std::fixed << std::setprecision(tolerance);
		std::cout << "double: " << f << std::endl;
	}
}

/* in scientific notation -3.40282e+38 means:
-3.40282 × 10^38 = -340,282,000,000,000,000,000,000,000,000,000,000,000
*/
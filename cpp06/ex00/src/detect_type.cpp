#include "../include/ScalarConverter.hpp"

bool	isPsoudo(const std::string &s);
int		isChar(const std::string &str, int len);
int		isInteger(const std::string &str, size_t len);
int		isFloat(const std::string &str, size_t len, size_t dot);
int		isDouble(const std::string &str, size_t len, size_t dot);
bool	isValid(const std::string &s);

bool	isPsoudo(const std::string &s)
{
	return (s == "nan" || s == "nanf" || s == "+inf" || s == "-inf"
		|| s == "+inff" || s == "-inff");
}
int	isChar(const std::string &str, int len)
{
	/* pares char */
	if (len == 1 && !isdigit(str[0]))
	{
		return (1);
	}
	if (len == 3 && str[0] == '\'' && str[2] == '\'')
	{
		std::cout << "empty\n";
		return (1);
	}
	return (0);
}

int	isInteger(const std::string &str, size_t len)
{
	size_t	i;
	int		sign;

	i = 0;
	sign = 0;
	if (str[0] == '-' || str[0] == '+')
	{
		sign = 1;
		i++;
	}
	while ((str[i] && len > 0 && len < 12) || (str[i] && !sign && len > 0
			&& len < 11))
	{
		if (!isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	isFloat(const std::string &str, size_t len, size_t dot)
{
	for (size_t i = 0; i < dot; i++)
	{
		if (!isdigit(str[i]) && i == 0 && str[i] != '-' && str[i] != '+')
			return (0);
		if (!isdigit(str[i]) && i != 0)
			return (0);
	}
	for (size_t j = dot + 1; j < len; j++)
	{
		if (!isdigit(str[j]) && str[j] != 'f' && str[j] != 'F' && (str[j] == 'e'
				&& str[j + 1] != '+'))
			return (0);
		if (str[j] == 'f' && str[j] == 'F' && j != len - 1)
			return (0);
	}
	return (1);
}
int	isDouble(const std::string &str, size_t len, size_t dot)
{
	for (size_t i = 0; i < dot; i++)
	{
		if (!isdigit(str[i]) && i == 0 && str[i] != '-' && str[i] != '+')
			return (0);
		if (!isdigit(str[i]) && i != 0)
			return (0);
	}
	for (size_t j = dot + 1; j < len; j++)
	{
		if (!isdigit(str[j]) && (str[j] == 'e' && str[j + 1] != '+'))
			return (0);
	}
	return (1);
}
bool	isValid(const std::string &s)
{
	size_t	i;
	int		d;
	int		f;

	d = 0;
	f = 0;
	// 42.42, 0.42, 0.f
	if (isPsoudo(s))
		return (true);
	if (!isdigit(s[0]) && s.size() == 1)
		return (true);
	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (; i < s.size(); ++i)
	{
		if (!isdigit(s[i]) && s[i] != '.' && s[i] != 'f' && s.size() > 1)
		{
			return (false);
		}
		if (s[i] == '.')
		{
			d++;
			if (d > 1)
				return (false);
		}
		if (s[i] == 'f')
		{
			f++;
			if (f > 1)
				return (false);
		}
	}
	return (true);
}

e_type	detectType(const std::string str, size_t len)
{
	std::size_t _dot = str.find('.');
	std::size_t _float = str.find('f');
	std::size_t _Float = str.find('F');
	std::size_t _exp = str.find('e');
	std::size_t _plus = str.find('+');
	std::size_t _mines = str.find('-');
	bool f_or_F = (_float != std::string::npos || _Float != std::string::npos); //exist f/F
	bool f_or_F_and_dot = ((_float != std::string::npos || _Float != std::string::npos) && _dot != std::string::npos);
	if ((_dot == std::string::npos)) // no dot
	{
		if (isPsoudo(str))
			return (SPECIAL);
		else
		{
			if (isChar(str, len))
				return (CHAR);
			if (isInteger(str, len))
				return (INT);
		}
	}
	/* pares int */
	else if (f_or_F || f_or_F_and_dot)
	{
		if (isFloat(str, len, _dot))
		{
			std::cout << "it is float" << std::endl;
			return (FLOAT);
		}
	}
	else if (_float == std::string::npos && ((_dot != std::string::npos)
			|| ((_mines != std::string::npos || _plus != std::string::npos)
				&& _exp != std::string::npos)))
	{
		if (isDouble(str, len, _dot))
			return (DOUBLE);
	}
	return (INVALID);
}

/*
(_exp != std::string::npos
			&& (_plus != std::string::npos || _mines != std::string::npos)
				&& _dot != std::string::npos
			&& (_float != std::string::npos || _Float != std::string::npos))
		|| (_exp != std::string::npos && (_plus != std::string::npos
				|| _plus != std::string::npos) && (_float != std::string::npos
			|| _Float != std::string::npos))

*/
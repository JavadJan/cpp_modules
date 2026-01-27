/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect_type.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhavari <mkhavari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 13:16:42 by mkhavari          #+#    #+#             */
/*   Updated: 2025/11/26 13:16:43 by mkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"

bool	isPsoudo(const std::string &s);
int		isChar(const std::string &str, int len);
int		isInteger(const std::string &str, size_t len);
int		isFloat(const std::string &str, size_t len, size_t dot);
int		isDouble(const std::string &str, size_t len, size_t dot);
// bool	isValid(const std::string &s);

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

// #include <iostream>
// #include <string>
// #include <cctype>

bool isFloat(const std::string &str)
{
    size_t i = 0;
    bool hasDot = false;
    bool hasExp = false;

    if (str.empty())
        return false;

    if (str[i] == '+' || str[i] == '-')
        i++;

    bool hasDigits = false;

    for (; i < str.size(); ++i)
    {
        char c = str[i];

        if (std::isdigit(c))
        {
            hasDigits = true;
            continue;
        }

        if (c == '.' && !hasDot && !hasExp)
        {
            hasDot = true;
            continue;
        }

        if ((c == 'e' || c == 'E') && !hasExp && hasDigits)
        {
            hasExp = true;
            hasDigits = false; // need digits after exponent
            if (i + 1 < str.size() && (str[i + 1] == '+' || str[i + 1] == '-'))
                i++; // skip sign
            continue;
        }

        if ((c == 'f' || c == 'F') && i == str.size() - 1)
            return hasDigits; // valid float suffix at end

        return false; // invalid character
    }

    return hasDigits;
}


bool isDouble(const std::string &str)
{
    size_t i = 0;
    bool hasDot = false;
    bool hasExp = false;

    if (str.empty())
        return false;

    if (str[i] == '+' || str[i] == '-')
        i++;

    bool hasDigits = false;

    for (; i < str.size(); ++i)
    {
        char c = str[i];

        if (std::isdigit(c))
        {
            hasDigits = true;
            continue;
        }

        if (c == '.' && !hasDot && !hasExp)
        {
            hasDot = true;
            continue;
        }

        if ((c == 'e' || c == 'E') && !hasExp && hasDigits)
        {
            hasExp = true;
            hasDigits = false; // must have digits after 'e' or 'E'
            if (i + 1 < str.size() && (str[i + 1] == '+' || str[i + 1] == '-'))
                i++; // skip sign after exponent
            continue;
        }
		if ((c == 'e' || c == 'E') && !hasExp && hasDigits)
		{
			hasExp = true;
			hasDigits = false;
			if (i + 1 < str.size() && (str[i + 1] == '+' || str[i + 1] == '-'))
				i++;
			continue;
		}


        // Any other character is invalid for a double
        return false;
    }

    return hasDigits;
}


e_type	detectType(const std::string str, size_t len)
{
    std::size_t _dot   = str.find('.');
    std::size_t _float = str.find('f');
    std::size_t _Float = str.find('F');
    std::size_t _exp   = str.find_first_of("eE");
    //std::size_t _plus  = str.find('+');
    //std::size_t _minus = str.find('-');

    bool f_or_F = (_float != std::string::npos || _Float != std::string::npos);
    bool e_exists = (_exp != std::string::npos);

    if (isPsoudo(str))
        return SPECIAL;

    // Integer or Char
    if (_dot == std::string::npos && !e_exists && !f_or_F)
    {
        if (isChar(str, len))
            return CHAR;
        if (isInteger(str, len))
            return INT;
    }

    // Float (with f/F at the end)
    else if (f_or_F)
    {
        if (isFloat(str))
            return FLOAT;
    }

    // Double (has '.' or 'e'/'E' and no trailing 'f')
    else if ((!f_or_F && (_dot != std::string::npos || e_exists)))
    {
        if (isDouble(str))
            return DOUBLE;
    }

    return INVALID;
}

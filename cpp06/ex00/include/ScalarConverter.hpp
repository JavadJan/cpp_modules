/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhavari <mkhavari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 13:16:29 by mkhavari          #+#    #+#             */
/*   Updated: 2025/11/26 13:16:31 by mkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ScalarConverter_hpp
# define ScalarConverter_hpp

#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>
#include <iomanip>
#include <limits>
#include <cerrno>
#include <cmath>


# define MIN_INT std::numeric_limits<int>::min() //-2147483648
# define MAX_INT std::numeric_limits<int>::max() //2147483647
#define MIN_FLOAT -3.402823466e+38F
#define MAX_FLOAT  3.402823466e+38F

#define MIN_DOUBLE -1.7976931348623158e+308
#define MAX_DOUBLE  1.7976931348623158e+308

enum    e_type
{
    SPECIAL = 0,
    CHAR = 1,
    INT = 2,
    FLOAT = 3,
    DOUBLE = 4,
    INVALID = -1
};

class ScalarConverter{

	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
	public: 
		static void convert(const std::string &str);
};


e_type	detectType(const std::string str, size_t len);

bool	isPsoudo(const std::string &s);
// bool	isValid(const std::string &s);
int 	isChar(const std::string &str, int len);
int 	isInteger(const std::string &str, size_t len);
//int		isFloat(const std::string &str, size_t len, size_t dot);
bool		isFloat(const std::string &str);
//int 	isDouble(const std::string &str, size_t len, size_t dot);
bool 	isDouble(const std::string &str);
e_type	detectType(const std::string str, size_t len);

void	Invalid(const std::string &s);
void	Char(const std::string &str);
void	Integer(const std::string &str);
void	Float(const std::string &str);
void	Double(const std::string &str);
void	Special(const std::string &str);

#endif


/* 

min() means smallest positive non-zero value (used for denormalized range checks).

lowest() means most negative representable value — which is what you want for range

*/
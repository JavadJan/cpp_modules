/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhavari <mkhavari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 14:47:36 by mkhavari          #+#    #+#             */
/*   Updated: 2026/01/28 14:47:38 by mkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RPN.hpp"
#include <ctype.h>

RPN::RPN()
{
}

RPN::~RPN()
{
}

RPN::RPN(const char *postfix)
{
	eval(postfix);
}

// RPN::RPN(const RPN &other)
//{
//	(void)other;
//}
// RPN &RPN::operator=(const RPN &other)
//{
//	if (this != &other)
//    	stack = other.stack;
//    return (*this);
//}

int	isOperand(char c)
{
	//size_t	s;

	// std::string symbols = "+-*/()^";
	// s = symbols.find(c);
	// if (s != std::string::npos)
	//	return (0);
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return (0);
	return (1);
}

int	isOperator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return (1);
	return (0);
}

void RPN::eval(const char *postfix)
{
	int	x1;
	int	x2;
	int	i;

	// Stack<int> st;
	i = 0;
	while (postfix[i] != '\0')
	{
		if (postfix[i] == ' ')
		{
			i++;
			continue ;
		}
		//if (isOperand(postfix[i]))
		if (isdigit(postfix[i]))
		{
			// std::cout << "pushed: " << postfix[i] - '0' << std::endl;
			stack.push(postfix[i] - '0');
		}
		else if (isOperator(postfix[i]))
		{
			if (stack.size() < 2)
        		throw Error();
			x2 = stack.top();
			stack.pop();
			x1 = stack.top();
			stack.pop();
			switch (postfix[i])
			{
			case '+':
			{
				// std::cout << x1 << ", " << x2 << std::endl;
				stack.push(x1 + x2);
				break ;
			}
			case '-':
			{
				stack.push(x1 - x2);
				break ;
			}
			case '*':
			{
				// std::cout << x1 << ", " << x2 << std::endl;
				stack.push(x1 * x2);
				break ;
			}
			case '/':
			{
				stack.push(x1 / x2);
				break ;
			}
			default:
				break ;
			}
		}
		else
			throw(Error());
		i++;
	}
	// return (stack.pop());
	x1 =  stack.top();
	stack.pop();
	if (stack.empty())
		std::cout << x1 << std::endl;
	else
		throw Error();
}

const char *RPN::Error::what() const throw()
{
	return ("Error\n");
}
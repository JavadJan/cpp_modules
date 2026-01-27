/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhavari <mkhavari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 13:12:20 by mkhavari          #+#    #+#             */
/*   Updated: 2025/11/27 13:12:21 by mkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/MutantStack.hpp"
#include <unistd.h>
#include <list>
int	main(void)
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	// == print mstack
	std::cout << "mstack: \n";
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	//---------------display s-----------
	std::cout << "display std::stack" << std::endl;
	while (!s.empty())
	{
		std::cout << s.top() << " ";
		s.pop();
	}
	std::cout << std::endl;

	// -----------------------------------------
	std::cout << "\033[33m" << "Test with rbegin and rend\n"<< "\033[0m";

	MutantStack<int>::reverse_iterator start = mstack.rbegin();
	MutantStack<int>::reverse_iterator end = mstack.rend();

	std::cout << "stack: ";
	while (start != end)
	{
		std::cout << *start << " ";
		++start;
	}
	std::cout << std::endl;
	return (0);
}

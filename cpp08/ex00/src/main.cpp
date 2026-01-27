/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhavari <mkhavari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 07:03:01 by mkhavari          #+#    #+#             */
/*   Updated: 2025/11/27 07:03:13 by mkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Easyfind.hpp"


int main( void ) 
{
	try
	{
		std::vector<int> v = {1, 2, 3};
		
		//std::array<int, 3> a = {7, 8, 9};
		std::cout << "found: ?" << *easyfind<std::vector<int>>(v, 2) << std::endl;
		std::cout << "found: ?" << *easyfind<std::vector<int>>(v, 5) << std::endl;
		

		//std::array<int> z = easyfind(a, 1);
		//std::cout << z << std::endl;
		//std::list<int>::iterator;
	
	}
	catch(const MyException& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		std::list<int> l = {4, 5, 6};
		std::list<int>::iterator x = easyfind<std::list<int>>(l, 4);
		std::cout << "\n\nfound: ? " << *x << std::endl;
		
		
		std::list<int>::iterator y = easyfind<std::list<int>>(l, 2);
		std::cout << " found: ?" << *y << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}

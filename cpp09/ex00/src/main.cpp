/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhavari <mkhavari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 15:19:57 by mkhavari          #+#    #+#             */
/*   Updated: 2026/01/27 16:09:13 by mkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/BitcoinExchange.hpp"
#include <unistd.h>
#include <list>
#include <fstream>

int	main(int ac, char *av[])
{
		
	try
	{
		if (ac != 2 || av[1] == NULL || av[1][0] == '\0')
			throw std::runtime_error("Error: could not open file.\n");
		
		std::string name = "./db/";
		name +=av[1];
		//std::cout << "path: " << name << std::endl;
		
		BitcoinExchange b(name.c_str());
		//std::cout << "path: " << name << std::endl;
		//std::cout << std::fixed << std::setprecision(2);

		b.print();
		//b.printDB();
	}
	catch(BitcoinExchange::ErrorOpen& e)
	{
		std::cerr << e.what();
	}
	catch(BitcoinExchange::BadFile& e)
	{
		std::cerr << e.what();
	}
	catch(BitcoinExchange::EmptyFile& e)
	{
		std::cerr << e.what();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}
	return (0);
}

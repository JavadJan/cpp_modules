/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhavari <mkhavari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 14:47:33 by mkhavari          #+#    #+#             */
/*   Updated: 2026/01/28 14:47:35 by mkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RPN.hpp"
#include <unistd.h>
#include <list>
#include <fstream>

int	main(int ac, char *av[])
{
		
	try
	{
		if (ac != 2 || av[1] == NULL || av[1][0] == '\0')
			throw std::runtime_error("Error: could not open file.\n");
		
		RPN rp(av[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}
	
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhavari <mkhavari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:44:26 by mkhavari          #+#    #+#             */
/*   Updated: 2026/04/15 21:05:53 by mkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av)
{
	int i = 1;

	if (ac < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		while (i < ac)
		{
			for (size_t j = 0; av[i][j]; j++)
			{
				av[i][j] << (char)toupper(av[i][j]) ;
			}
			std::cout << av[i] ;
			if (av[i] != NULL)
				std::cout << " ";
			i++;
		}
		std::cout << std::endl;
	}
	return (0);
}

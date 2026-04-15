/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhavari <mkhavari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 21:30:24 by mkhavari          #+#    #+#             */
/*   Updated: 2025/09/03 21:30:26 by mkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
	if (!(ac < 3 && ac > 1))
	{
		std::cout << "Invalid argument\n";
		return (1);
	}
	Harl harl;
	harl.complain(std::string(av[1]));
	return (0);
}
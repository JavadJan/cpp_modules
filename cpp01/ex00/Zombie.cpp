/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhavari <mkhavari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 21:29:24 by mkhavari          #+#    #+#             */
/*   Updated: 2025/09/03 21:29:26 by mkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::~Zombie()
{
	std::cout << "\033[1;31m" << this->name << ": destroyed 🧟🏳️" << "\033[0m" << std::endl;
}

Zombie::Zombie() : name("")
{
}

Zombie::Zombie(std::string name)
{
	this->name = name;
}
// Zombie::Zombie(std::string name) : name(name) {} //with list ininzializer

void	Zombie::announce()
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ...\n" ;
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhavari <mkhavari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 21:28:24 by mkhavari          #+#    #+#             */
/*   Updated: 2025/09/03 21:28:26 by mkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
	
Zombie* newZombie( std::string name);
void randomChump( std::string name );

int main()
{
	Zombie *z = newZombie("foo");
	randomChump("javad");
	z->announce();
	delete(z);
	return (0);
}
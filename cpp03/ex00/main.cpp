/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhavari <mkhavari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:16:00 by mkhavari          #+#    #+#             */
/*   Updated: 2026/04/15 21:20:40 by mkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
    //hit_points     = 10;
	//energy_points  = 10;
	//attack_damage  = 0;


	std::cout << "\033[4;31mFirst lest's test the Canonical Form: \033[0m" << std::endl;
	ClapTrap c;
	ClapTrap cc("TEST");
	ClapTrap b(cc);
	c = b;
	
	std::cout << "\033[4;32m\n\nStart the main action: \033[0m" << std::endl;
	ClapTrap a("Javad");
	a.attack("Target1");  // Should print attack message and reduce energy -1
	a.takeDamage(3);  // Should reduce: (hit-points -3 = 7) && enrgy-point -1 == 9

    a.beRepaired(5);  // Should increase: (hit-points +5 = 12) && energy-points-- == 8

    for (int i = 0; i < 10; ++i) //energy == 8, 8 attack then no battrey to attack
        a.attack("Dummy");  // Eventually should run out of energy and 8 times attack and 2 times dead
    a.takeDamage(100);     // Should bring hit points to 0

    a.attack("Somebody");    // Should not be allowed
    a.beRepaired(5);       // Should not be allowed

	
    return 0;
}
/* base class: GAOL: just intuduction of definintion and class to next execersise
	damage because the subject explicitly initializes attackDamage = 0

	1. define 4 attribute as priavte
	2. define 4 getter to return those parameter
	3. notice: define 3 fnction member, and worked the curret ptr(*this) to calculation,  


	// damage is 0 because attack_damage is initialized to 0
*/
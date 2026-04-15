/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhavari <mkhavari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:16:00 by mkhavari          #+#    #+#             */
/*   Updated: 2026/04/15 21:22:11 by mkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {



	std::cout << "\033[4;31m[TEST-1]: First lest's test the Canonical Form: \033[0m" << std::endl;
	ClapTrap c0;
	ClapTrap cc("TEST");
	ClapTrap b(cc);
	c0 = b;
	

	std::cout << "\033[33m\n--------------------------\n\n\033[0m";
	
	
	std::cout << "\033[1;34m[TEST0]: Derived default constructor in inheritance\033[0m" << std::endl;
	ScavTrap c;

	std::cout << "\033[1;34m\n[TEST1]: Derived constructor with pararmeter in inheritance(how order?)\033[0m" << std::endl;
	ScavTrap d("Najla");
	
	std::cout << "\033[1;34m\n[TEST2]: Derived copy constructor in inheritance(how order?)\033[0m" << std::endl;
	ScavTrap p(c);

	std::cout << "\033[1;34m\n[TEST3]: Derived copy assignment constructor in inheritance(how order?)\033[0m" << std::endl;
	ScavTrap co;
	co = c;

	std::cout << "\033[1;34m\n\n[TEST4]: Override method attack without param: \033[0m" << std::endl;
	c.attack("ClapTrap"); // c attck Claptrap, attack is also a Base memeber ScavTrap ;
	std::cout << "\033[1;33m----->called repaire and takeDamage from base; so it print message from base clss\033[0m" << std::endl;
	c.beRepaired(22); // ScavTrap(this->name) repair and get hit_points += 22, but base class is running and base == ClapTrap.
	// if you want here the method from base class is running
	c.takeDamage(21); // ScavTrap should take_damage but, runs method damage from Base, and Base is CalpTrap take damage?
	c.beRepaired(22); // The ScavTrap shouild be repaired but the thie method runs from base, without override?
	std::cout << "\033[1;34m\n[TEST5]: extra method from base class: \033[0m" << std::endl;
	c.guardGate();		// ScavTrap exe the quardGate, this method is in derived ScavTrap		// this one alos a memeber dreived ScavTrap
	
	std::cout << "\033[31m---------------------------------\033[0m" << std::endl;
	std::cout << "\033[1;34m\n\n[TEST6]: Override with param: \033[0m" << std::endl;
	d.attack("Najla-clone");	// run from derived class because you override it
	d.beRepaired(21);	// run from base clase, unless you override it
	d.takeDamage(21);	// run from base class, unless you override it
	d.takeDamage(101);	// run from base class unless you override it
	d.takeDamage(15);	// run from base class unless you do polyporphism
	d.attack("ScavTrap");
	d.guardGate();

	std::cout << "\033[34m\n\n[TEST7]: (FragTrap())------\033[0m" << std::endl;

	std::cout << "\033[32m-------TEST FRAGTRAP WITHOUT PARAM: (FragTrap())------\033[0m" << std::endl;
	FragTrap f;
	f.attack("javad");

	FragTrap f0("Foo"); // after copy
	f = f0;

	f.attack("javad");
	
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "\033[32m-------TEST FRAGTRAP WITH PARAM: (FragTrap(std::string name))------\033[0m" << std::endl;
	FragTrap fr("Evaluator"); // create a FragTrap with name == evaluator
	fr.attack("javad");	// evaluator attack javad
	fr.beRepaired(30);	// beRepairing run from base class
	fr.takeDamage(20);	// takeDamage run from base class
	
	
	fr.highFivesGuys();
	
	
	std::cout << std::endl;
	
	std::cout << "\033[32m[TEST8]: in order constructor\033[0m" << std::endl;
	FragTrap f1("f1");
	std::cout << "\033[32m#######################\033[0m" << std::endl;
	FragTrap f2("f2");
	std::cout << "\033[32m#######################\033[0m" << std::endl;
	FragTrap f3("f3");
	std::cout << "\033[32m#######################\033[0m" << std::endl;
	FragTrap f4("f4");
	std::cout << "\033[32m#######################\033[0m" << std::endl;
	FragTrap f5("f5");
	std::cout << "\033[32m#######################\033[0m" << std::endl;
	FragTrap f6("f6");
	std::cout << "\033[32m#######################\033[0m" << std::endl;
	FragTrap f7("f7");
	std::cout << "\033[32m#######################\033[0m" << std::endl;
	FragTrap f8("f8");
	std::cout << "\033[32m#######################\033[0m" << std::endl;
	
	std::cout << "\033[1;34m\n\n[TEST DeSTRUCTOR]: calling as many as object we created\033[0m" << std::endl;
    return 0;
}

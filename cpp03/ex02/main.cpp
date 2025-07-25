#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {

	//hit_points     = 10;
	//energy_points  = 10;
	//attack_damage  = 0;
	std::cout << "\033[32m-------TEST CLAPTRAP WITH PARAM: (FragTrap())------\033[0m" << std::endl;
	ClapTrap a("Javad");

    a.attack("Target1");  // Should print attack message and reduce energy -1
    a.takeDamage(3);  // Should reduce hit-points -3 = 7,  enrgy-point -1 = 9
    a.beRepaired(5);  // Should increase hit-points +5 = 12 and reduce energy-points-- → 8
    for (int i = 0; i < 10; ++i) //energy == 8, 8 attack then no battrey to attack
        a.attack("Dummy");  // Eventually should run out of energy
    a.takeDamage(100);     // Should bring hit points to 0
    a.attack("Nobody");    // Should not be allowed
    a.beRepaired(5);       // Should not be allowed

	std::cout << std::endl;
	//Proper construction/destruction chaining must be shown in your tests.
	std::cout << "\033[32m-------TEST FRAGTRAP WITHOUT PARAM: (FragTrap())------\033[0m" << std::endl;
	FragTrap f;
	f.attack("javad");
	//f.beRepaired(5);
	f.takeDamage(5);
	for (size_t i = 0; i < 10; i++)
	{
		f.attack("javad");
	}
	f.takeDamage(100);
	f.beRepaired(5);
	



	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "\033[32m-------TEST FRAGTRAP WITH PARAM: (FragTrap(std::string name))------\033[0m" << std::endl;
	FragTrap fr("Evaluator"); // create a FragTrap with name == evaluator
	fr.attack("javad");	// evaluator attack javad
	fr.beRepaired(30);	// beRepairing run from base class
	fr.takeDamage(20);	// takeDamage run from base class


	fr.highFivesGuys();
	
	
	std::cout << std::endl;
	std::cout << "\033[32m-------CALLED DESTRUCTOR IN REVERSE ORDER------\033[0m" << std::endl;
    return 0;
}

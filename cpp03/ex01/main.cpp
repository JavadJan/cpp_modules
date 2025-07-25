#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {

	//hit_points     = 10;
	//energy_points  = 10;
	//attack_damage  = 0;

	ClapTrap a("Javad");

    a.attack("Target1");  // Should print attack message and reduce energy -1
    a.takeDamage(3);  // Should reduce hit-points -3 = 7,  enrgy-point -1 = 9
    a.beRepaired(5);  // Should increase hit-points +5 = 12 and reduce energy-points-- → 8
    for (int i = 0; i < 10; ++i) //energy == 8, 8 attack then no battrey to attack
        a.attack("Dummy");  // Eventually should run out of energy
    a.takeDamage(100);     // Should bring hit points to 0
    a.attack("Nobody");    // Should not be allowed
    a.beRepaired(5);       // Should not be allowed



	std::cout << "\033[33m\n--------------------------\n\n\033[0m";
	//ScavTrap and will inherit the constructors and destructor from Clap-Trap.
    //ScavTrap s1; // first base(ClapTrap) class construcotr run then ScavTrap run
	//ScavTrap s1("Scavvy");

	//s1.attack("bad guy");     // Should use ScavTrap's overridden attack
	//s1.takeDamage(10);        // Inherited from ClapTrap
	//s1.beRepaired(5);         // Inherited from ClapTrap

	//s1.guardGate();

	std::cout << "\033[34mTESTConstructing\033[0m" << std::endl;
	ScavTrap c; // test without praram c == ScavTrap the name is empty
	
	std::cout << "\033[31m---------------------------------\033[0m" << std::endl;
	std::cout << "\033[34mTesting Behavior without params construcotr: \033[0m" << std::endl;
	c.attack("ClapTrap"); // c attck Claptrap, attack is also a Base memeber ScavTrap ;
	c.beRepaired(22); // ScavTrap(this->name) repair and get hit_points += 22, but base class is running and base == ClapTrap.
	// if you want here the method from base class is running
	c.takeDamage(21); // ScavTrap should take_damage but, runs method damage from Base, and Base is CalpTrap take damage?
	c.beRepaired(22); // The ScavTrap shouild be repaired but the thie method runs from base, without override?
	c.guardGate();		// ScavTrap exe the quardGate, this method is in derived ScavTrap
	c.guardGate();		// this one alos a memeber dreived ScavTrap
	
	std::cout << "\033[31m---------------------------------\033[0m" << std::endl;
	std::cout << "\033[34mTesting Behavior with params: \033[0m" << std::endl;
	ScavTrap d("Najla"); //test with params
	d.attack("Najla-clone");	// run from derived class because you override it
	d.beRepaired(21);	// run from base clase, unless you override it
	d.takeDamage(21);	// run from base class, unless you override it
	d.takeDamage(101);	// run from base class unless you override it
	d.takeDamage(15);	// run from base class unless you do polyporphism
	d.attack("ScavTrap");	// 
	d.guardGate();
	d.guardGate();
	std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
    return 0;
}

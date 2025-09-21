#include "ClapTrap.hpp"

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
    a.attack("Somebody");    // Should not be allowed
    a.beRepaired(5);       // Should not be allowed

	
    return 0;
}
/* base class:
	damage because the subject explicitly initializes attackDamage = 0

	1. define 4 attribute as priavte
	2. define 4 getter to return those parameter
	3. notice: define 3 function member, and worked the curret ptr(*this) to calculation,  
*/
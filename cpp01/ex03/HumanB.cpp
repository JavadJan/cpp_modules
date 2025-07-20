#include "HumanB.hpp"


HumanB::~HumanB()
{

}

HumanB::HumanB(std::string name): name(name), weapon(NULL)
{

}

std::string HumanB::getName() const
{
	return (this->name);
}

void HumanB::setWeapon(Weapon& new_weapon) {
	this->weapon = &new_weapon;
}
//it takes the address of that reference (&newWeapon) and stores it in the pointer weapon.
void HumanB::attack()
{
	if (weapon)
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}
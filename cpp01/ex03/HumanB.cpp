#include "./include/HumanB.hpp"


HumanB::~HumanB()
{
	std::cout << "\033[1;31mCalled destructor HumanB\033[0m" << std::endl;
}

HumanB::HumanB(std::string name):name(name), weapon(NULL)
{
	std::cout << "\033[1;32mCalled constructor HumanB with parameter!\033[0m" << std::endl;
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
#include "HumanA.hpp"

//HumanA::HumanA()
//{
//	// when a class has &ref or *ptr in variable member, use from initializer
//}
HumanA::~HumanA()
{
	
}

Weapon& HumanA::getWeapon() const{
	return (this->weapon);
}
std::string HumanA::getName() const{
	return (this->name);
}

HumanA::HumanA(std::string name, Weapon& weapon) :name(name), weapon(weapon)
{

}

void HumanA::attack()
{
	std::cout << this->getName() << " attacks with their " << this->weapon.getType() << '\n';
}
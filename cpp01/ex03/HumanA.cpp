/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhavari <mkhavari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 21:29:55 by mkhavari          #+#    #+#             */
/*   Updated: 2025/09/03 21:29:57 by mkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/HumanA.hpp"

//HumanA::HumanA()
//{
//	// when a class has &ref or *ptr in variable member, use from initializer
//}
HumanA::~HumanA()
{
	std::cout << "\033[1;31mCalled destructor HumanA\033[0m" << std::endl;
}

const Weapon& HumanA::getWeapon() const {
    return this->weapon;
}

std::string HumanA::getName() const{
	return (this->name);
}

HumanA::HumanA(std::string name, Weapon& weapon) : name(name), weapon(weapon)
{
	std::cout << "\033[1;32mCalled constructor HumanA with parameter!\033[0m" << std::endl;
}

void HumanA::attack()
{
	std::cout << this->getName() << " attacks with their " << this->weapon.getType() << '\n';
}
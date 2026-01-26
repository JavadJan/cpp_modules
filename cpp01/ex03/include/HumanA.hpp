#ifndef HUMANA_HPP
#define HUMANA_HPP
#include "Weapon.hpp"

class HumanA
{
	private:
		std::string name;
		Weapon& weapon; // &non-null
	public:
		//HumanA();
		HumanA(std::string name, Weapon& weapon);
		~HumanA();
		//HumanA( const HumanA& other) // copy constructor, duplicate
		//HumanA& operator = (const HumanA& other);
		const Weapon& getWeapon() const;
		std::string getName() const;
		void  attack();
};

#endif
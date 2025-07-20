#ifndef HUMANB_HPP
#define HUMANB_HPP
#include "Weapon.hpp"

class HumanB
{
	private:
		Weapon* weapon; // can take null
		std::string name;
	public:
		HumanB(std::string name);
		~HumanB();
		//HumanA( const HumanA& other) // copy constructor, duplicate
		//HumanA& operator = (const HumanA& other);
		std::string getName() const;
		void setWeapon(Weapon& new_weapon);
		void  attack();
};

#endif

//Use a reference (Weapon&) when:
//The object must always have a weapon (non-null).
//The weapon is guaranteed to exist for the lifetime of the user.
//You're enforcing ownership or identity — it’s required.
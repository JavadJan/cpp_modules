#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int	main(void)
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club); // HumanA uses from &, non-null
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim"); // can take null
		jim.setWeapon(club); // when you call set, should n't be null
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
}
//HumanB may not always have a weapon, define as *ptr to weapon
// whereas HumanA will always be armed. define as ref& to weapon
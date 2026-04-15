/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhavari <mkhavari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 21:30:01 by mkhavari          #+#    #+#             */
/*   Updated: 2025/09/03 21:30:03 by mkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/HumanA.hpp"
#include "./include/HumanB.hpp"
#include "./include/Weapon.hpp"

int	main(void)
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club); // HumanA uses from &, non-null
		// HumanA bob("Bob"); // HumanA uses from &, non-null
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim"); // can take null
		// HumanB jim("Jim", club); // can take null
		jim.setWeapon(club); // when you call set, should n't be null
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
}
// HumanB may not always have a weapon, define as *ptr to weapon
// whereas HumanA will always be armed. define as ref& to weapon

/*	GOAL: & can not be null; most init them
	HumanA is used &, that can be have type null, because it uses the &;
	HumanB is used for *, that can be have nothing for its type.

	If you declare a reference (&) as a member,
		it must be initialized in the constructor’s initializer list — otherwise the class cannot be instantiated.
	If your class has a reference member (&),
		the compiler cannot generate a default constructor,
		because it would have no way to initialize the reference.
	So you must provide a constructor that initializes the reference.

	References are aliases,
		not pointers — they must always refer to a valid object from the moment the containing object is created.
*/
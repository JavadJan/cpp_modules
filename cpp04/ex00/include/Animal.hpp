/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhavari <mkhavari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 22:16:53 by mkhavari          #+#    #+#             */
/*   Updated: 2025/09/24 22:16:55 by mkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ANIMAL_HPP
#define	ANIMAL_HPP
#include <iostream>

#define DEUBG 1

class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		Animal(const std::string &name);
		~Animal();
		Animal(const Animal& other);
		Animal& operator=(const Animal& other);
		virtual void makeSound() const; // test here without virtual in eval time and show running time 
		std::string getType() const;
};
#endif

/* 
    "Dog" is litral string and it is const
	Making the destructor virtual ensures that when you delete an object
 	through a pointer to the base type (Animal* p = new Dog(); delete p;), the derived class’s destructor runs too. 
*/
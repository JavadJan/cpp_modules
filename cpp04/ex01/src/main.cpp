/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhavari <mkhavari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 22:18:10 by mkhavari          #+#    #+#             */
/*   Updated: 2025/09/25 08:19:14 by mkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"
#include "../include/WrongAnimal.hpp"
#include "../include/Cat.hpp"
#include "../include/WrongCat.hpp"
#include "../include/Dog.hpp"

int main()
{
	if (DEBUG == 0)
	{
		std::cout << "\033[31m-----------TEST ANIMAL-----------------" << std::endl;
		const Animal* meta = new Animal();
		std::cout << meta->getType() << std::endl;
		meta->makeSound();
		
		delete meta;
		std::cout << std::endl;
		std::cout << "\033[33m-----------TEST CAT-----------------" << std::endl;
		//Cat c("meow1");
		const Animal* i = new Cat();
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		
		const Animal* ii = new Cat("cat0");
		std::cout << ii->getType() << " " << std::endl;
		ii->makeSound(); //will output the cat sound!


		std::cout << "\033[33m[EXPECTED]: Cat destructor-----------: " << std::endl;
		delete i;
		std::cout << "\033[33m[EXPECTED]: Dog destructor-----------: " << std::endl;
		delete ii;
		std::cout << std::endl;
		std::cout << "\033[34m-----------TEST DOG-----------------" << std::endl;
		//Dog d("Woof1");
		const Animal* j = new Dog(); // it is empyu, so getType is empty
		std::cout << j->getType() << " " << std::endl;
		j->makeSound();
		const Animal* jj = new Dog("dog0"); // it is empyu, so getType is empty
		std::cout << jj->getType() << " " << std::endl;
		jj->makeSound();
		
		delete j;
		delete jj;
		std::cout << "\033[31m\n\n-----------TEST WRONG ANIMAL-----------------" << std::endl;
		WrongAnimal *animal = new WrongAnimal("WrongAnimal");
		std::cout << animal->getType() << std::endl;
		animal->makeSound();
		
		WrongAnimal *k = new WrongCat();
		std::cout << k->getType() << std::endl;
		k->makeSound();
		
		delete animal;
		delete k;
		std::cout << "\033[31m\n\n-----------TEST ARRAY WRONG ANIMAL-----------------" << std::endl;
		WrongAnimal *an [] = {
		new WrongAnimal("WrongAnimal0"),
		new WrongAnimal("WrongAnimal1"),
		new WrongAnimal("WrongAnimal2"),
		new WrongAnimal("WrongAnimal3"),
		new WrongAnimal("WrongAnimal4"),

		new WrongCat("WrongCat0"),
		new WrongCat("WrongCat1"),
		new WrongCat("WrongCat2"),
		new WrongCat("WrongCat3"),
		new WrongCat("WrongCat4")
		};
		for (size_t i = 0; i < 10; i++)
		{
			an[i]->makeSound();
		}
		std::cout << std::endl;
	}
	std::cout << "\033[31m\n\n-----------TEST ARRAY OF OBJECT ANIMALs-----------------" << std::endl;
	Animal *an [] = {
		new Cat("cat0"),
		new Cat("cat1"),
		new Cat("cat2"),
		new Cat("cat3"),
		new Cat("cat4"),

		new Dog("dog0"),
		new Dog("dog1"),
		new Dog("dog2"),
		new Dog("dog3"),
		new Dog("dog4")
	};
	for (size_t i = 0; i < 10; i++)
	{
		an[i]->makeSound();
	}


	std::cout << "\033[35m\n\n-----------TEST Deep copy-----------------" << std::endl;
	Dog dog1;
	dog1.setIdea(0, "Play fetch");
	dog1.setIdea(1, "Eat bone");

	Dog dog2 = dog1;  // Copy constructor
	std::cout << "dog1 ideas: " << dog1.getIdea(0) << ", " << dog1.getIdea(1) << std::endl;
	std::cout << "dog2 ideas: " << dog2.getIdea(0) << ", " << dog2.getIdea(1) << std::endl;

	std::cout << "set new var" << std::endl;
	dog2.setIdea(0, "Sleep");
	dog2.setIdea(1, "Bark");

	std::cout << "dog1 ideas: " << dog1.getIdea(0) << ", " << dog1.getIdea(1) << std::endl;
	std::cout << "dog2 ideas: " << dog2.getIdea(0) << ", " << dog2.getIdea(1) << std::endl;


	
	std::cout << "\033[35m\n\n-----------Called Deconstructors-----------------" << std::endl;
	for (size_t i = 0; i < 10; i++)
	{
		delete an[i];
	}
	
	return (0);
}
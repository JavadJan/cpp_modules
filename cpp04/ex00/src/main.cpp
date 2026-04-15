/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhavari <mkhavari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 22:17:22 by mkhavari          #+#    #+#             */
/*   Updated: 2025/09/25 07:08:49 by mkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"
#include "../include/WrongAnimal.hpp"
#include "../include/Cat.hpp"
#include "../include/WrongCat.hpp"
#include "../include/Dog.hpp"

int main()
{

	if (DEUBG == 0)
	{
		std::cout << "\033[1;31m-----------TEST ANIMAL-----------------" << std::endl;
		const Animal meta = Animal();
		const Dog j = Dog();
		const Cat i = Cat();
		std::cout << j.getType() << " " << std::endl;
		std::cout << i.getType() << " " << std::endl;
		i.makeSound(); //will output the cat sound!
		j.makeSound();
		meta.makeSound();
		// delete j;
		// delete i;
		// delete meta;
	}
	else
	{
		std::cout << "\033[31m-----------TEST ANIMAL: BASE-----------------" << std::endl;
		const Animal* meta = new Animal();
		std::cout << meta->getType() << std::endl;
		meta->makeSound();
		// delete meta;
		// std::cout << "delete meta obj and deallocate memory" ;
		std::cout << std::endl;
		std::cout << std::endl;
		
		std::cout << "\033[33m-----------TEST CAT with PTR* Animal-----------------" << std::endl;
		//Cat c("meow1");
		const Animal* i = new Cat();
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		
		const Animal* ii = new Cat("cat0");
		std::cout << ii->getType() << " " << std::endl;
		ii->makeSound(); //will output the cat sound!
	
	
		// delete i;
		// delete ii;
		std::cout << std::endl;
		std::cout << "\033[34m-----------TEST DOG with PTR* Animal-----------------" << std::endl;
		//Dog d("Woof1");
		const Animal* j = new Dog(); // it is empyu, so getType is empty
		std::cout << j->getType() << " " << std::endl;
		j->makeSound();
		const Animal* jj = new Dog("dog0"); // it is empyu, so getType is empty
		std::cout << jj->getType() << " " << std::endl;
		jj->makeSound();
		
		// delete j;
		// delete jj;
		std::cout << "\033[31m\n\n-----------TEST WRONG ANIMAL-----------------" << std::endl;
		const WrongAnimal *animal = new WrongAnimal("WrongAnimal");
		// first call constructor then alloc memory in heap for object?
		std::cout << animal->getType() << std::endl;
		animal->makeSound();
	
		std::cout << std::endl;
		const WrongAnimal *WCat = new WrongCat(); 
		std::cout << WCat->getType() << std::endl;
		WCat->makeSound();
		
		// delete animal;
		// delete WCat;
		std::cout << std::endl;
		std::cout << "\033[35m-----------Called Destructor-----------------" << std::endl;
	}
	return (0);
}
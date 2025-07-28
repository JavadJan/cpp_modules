#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"

int main()
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


	delete i;
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
	std::cout << std::endl;
	std::cout << "\033[35m-----------Called Destructor-----------------" << std::endl;
	return (0);
}
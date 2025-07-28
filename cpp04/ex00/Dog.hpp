#ifndef	DOG_HPP
#define	DOG_HPP
#include "Animal.hpp"
#include <iostream>

class Dog: public Animal
{
	public:
		Dog();
		Dog(std::string type);
		~Dog();
		Dog(const Dog& other);
		Dog& operator=(const Dog& other);
		void makeSound() const;


};

#endif
#ifndef	ANIMAL_HPP
#define	ANIMAL_HPP
#include <iostream>

class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		Animal(std::string type);
		virtual ~Animal();
		Animal(const Animal& other);
		Animal& operator=(const Animal& other);
		virtual void makeSound() const = 0; // if assgin to 0, then it becomes to abstract class
		std::string getType() const;
};
#endif
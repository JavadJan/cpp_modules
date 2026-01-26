#ifndef	CAT_HPP
#define	CAT_HPP
#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Cat: public Animal
{
	private:
		Brain *brain;
	public:
		Cat();
		Cat(std::string type);
		~Cat();
		Cat(const Cat& other);
		Cat& operator=(const Cat& other);
		void makeSound() const;

				/* getter */
		std::string getIdea(int index);
		/* setter */
		void setIdea(int pos, std::string idea);
};

#endif
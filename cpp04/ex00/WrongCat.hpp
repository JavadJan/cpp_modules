#ifndef	WRONGCAT_HPP
#define	WRONGCAT_HPP
#include "WrongAnimal.hpp"
#include <iostream>

class WrongCat: public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(std::string type);
		~WrongCat();
		WrongCat(const WrongCat& other);
		WrongCat& operator=(const WrongCat& other);
		void makeSound() const;

		/* getter */
		//std::string getType() const;
};

#endif
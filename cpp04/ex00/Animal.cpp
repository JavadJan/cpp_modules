#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "\033[32mCalled Base Animal Cosntructor\033[0m" << std::endl; 
}

Animal::Animal(std::string name): type(name)
{
	std::cout << "\033[32mCalled Base Animal with param Cosntructor\033[0m" << std::endl; 
}

Animal::~Animal()
{
	std::cout << "\033[32mCalled Base Animal Decosntructor\033[0m" << std::endl; 
}
Animal::Animal(const Animal& other)
{
	std::cout << "\033[32mCalled Base Animal Copy Cosntructor\033[0m" << std::endl; 
	*this = other; // called assign copy constructor
}

Animal& Animal::operator=(const Animal& other)
{
	std::cout << "\033[32mCalled Base Animal  assignment Cosntructor\033[0m" << std::endl; 
	if (this != &other)
	{
		this->type = other.type;
	}
	return (*this);
}

std::string Animal::getType() const
{
	return this->type;
}

void Animal::makeSound() const
{
	std::cout << "khoor pooof" << std::endl;
}
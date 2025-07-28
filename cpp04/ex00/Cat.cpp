#include "Cat.hpp"

Cat::Cat():Animal("Cat")
{
	std::cout << "\033[33mCalled Cat Cosntructor\033[0m" << std::endl; 
}

Cat::Cat(std::string name): Animal(name)
{
	std::cout << "\033[33mCalled Cat with type Cosntructor\033[0m" << std::endl; 
}
Cat::~Cat()
{
	std::cout << "\033[33mCalled Cat Decosntructor\033[0m" << std::endl; 
}
Cat::Cat(const Cat& other)
{
	std::cout << "\033[33mCalled Cat Copy Cosntructor\033[0m" << std::endl; 
	*this = other; // called the assign constructor
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "\033[33mCalled Cat  assignment Cosntructor\033[0m" << std::endl; 
	if (this != &other)
	{
		this->type = other.type;
	}
	return (*this);
}

//std::string Cat::getType()
//{
//	return (this->type);
//}

void Cat::makeSound() const
{
	std::cout << "Meow, Moew, Meow! 🐈" << std::endl;
}
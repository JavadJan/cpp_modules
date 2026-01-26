#include "Dog.hpp"

Dog::Dog():Animal("Dog")
{
	std::cout << "\033[34mCalled Dog Cosntructor\033[0m" << std::endl; 
}

Dog::Dog(std::string name): Animal(name)
{
	std::cout << "\033[34mCalled Dog with type Cosntructor\033[0m" << std::endl; 
}
Dog::~Dog()
{
	std::cout << "\033[34mCalled Dog Decosntructor\033[0m" << std::endl; 
}
Dog::Dog(const Dog& other)
{
	std::cout << "\033[34mCalled Dog Copy Cosntructor\033[0m" << std::endl; 
	*this = other;
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << "\033[34mCalled Dog  assignment Cosntructor\033[0m" << std::endl; 
	if (this != &other)
	{
		this->type = other.type;
	}
	return (*this);
}

//std::string Dog::getType()
//{
//	return (this->type);
//}

void Dog::makeSound() const
{
	std::cout << "Bark, Bark, Bark! 🐕" << std::endl;
}
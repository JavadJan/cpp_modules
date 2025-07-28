#include "./include/WrongCat.hpp"

WrongCat::WrongCat():WrongAnimal("WrongCat")
{
	std::cout << "\033[33mCalled WrongCat Cosntructor\033[0m" << std::endl; 
}

WrongCat::WrongCat(std::string name): WrongAnimal(name)
{
	std::cout << "\033[33mCalled WrongCat with type Cosntructor\033[0m" << std::endl; 
}
WrongCat::~WrongCat()
{
	std::cout << "\033[33mCalled WrongCat Decosntructor\033[0m" << std::endl; 
}
WrongCat::WrongCat(const WrongCat& other)
{
	std::cout << "\033[33mCalled WrongCat Copy Cosntructor\033[0m" << std::endl; 
	*this = other;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	std::cout << "\033[33mCalled WrongCat  assignment Cosntructor\033[0m" << std::endl; 
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

void WrongCat::makeSound() const
{
	std::cout << "Meow, Moew, Meow! 🐈" << std::endl;
}
#include "./include/Cat.hpp"

Cat::Cat():Animal("Cat") , brain(new Brain()) 
{
	//Call Brain's default constructor to initialize it.
	//It avoids default-initializing brain first, then overwriting it.
	//brain = new Brain();
	std::cout << "\033[33mCalled Cat Cosntructor, and get BRAIN\033[0m" << std::endl; 
}

Cat::Cat(std::string name): Animal(name)
{
	std::cout << "\033[33mCalled Cat with type Cosntructor\033[0m" << std::endl; 
	this->type = name;
	this->brain = new Brain();
	if (this->brain == NULL)
	{
		perror("Dog Brain allocation failed");
		std::cerr << "Exiting the process now." << std::endl;
		exit(1);
	}
}
Cat::~Cat()
{
	delete brain;
	std::cout << "\033[33mCalled Cat Decosntructor\033[0m" << std::endl; 
}
Cat::Cat(const Cat& other): Animal(other)
{
	std::cout << "\033[33mCalled Cat Copy Cosntructor\033[0m" << std::endl; 
	brain = new Brain(*other.brain);  // Deep copy the brain
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

std::string Cat::getIdea(int index)
{
	return (this->brain->ideas[index]);
}

void Cat::setIdea(int pos, std::string idea)
{
	this->brain->ideas[pos] = idea;
}

void Cat::makeSound() const
{
	std::cout << "Meow, Moew, Meow! 🐈" << std::endl;
}
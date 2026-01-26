#include "./include/Dog.hpp"

Dog::Dog():Animal("Dog"), brain(new Brain())
{
	//brain = new Brain();
	std::cout << "\033[34mCalled Dog Cosntructor and get BRAIN\033[0m" << std::endl; 
}

Dog::Dog(std::string name): Animal(name)
{
	std::cout << "\033[34mCalled Dog with type Cosntructor\033[0m" << std::endl;
	this->type = name;
	this->brain = new Brain();
	if (this->brain == NULL)
	{
		perror("Dog Brain allocation failed");
		std::cerr << "Exiting the process now." << std::endl;
		exit(1);
	}
}
Dog::~Dog()
{
	delete brain;
	std::cout << "\033[34mCalled Dog Decosntructor\033[0m" << std::endl; 
}

Dog::Dog(const Dog& other) : Animal(other) {
	std::cout << "\033[34mCalled Dog Copy Cosntructor\033[0m" << std::endl; 
	brain = new Brain(*other.brain);  // Deep copy the brain
}


Dog& Dog::operator=(const Dog& other)
{
	std::cout << "\033[34mCalled Dog  assignment Cosntructor\033[0m" << std::endl; 
	if (this != &other)
	{
		Animal::operator=(other); // copy the type
		*this->brain = *other.brain; // copy with value
	}
	this->type = other.type; // shallow copy
	//Dog objects will point to the same Brain object in memory.
	return (*this);
}

std::string Dog::getIdea(int index)
{
	return (this->brain->ideas[index]);
}

void Dog::setIdea(int pos, std::string idea)
{
	this->brain->ideas[pos] = idea;
}

void Dog::makeSound() const
{
	std::cout << "Bark, Bark, Bark! 🐕" << std::endl;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhavari <mkhavari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 22:18:06 by mkhavari          #+#    #+#             */
/*   Updated: 2025/09/25 08:10:38 by mkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"

Dog::Dog():Animal("Dog"), brain(new Brain())
{
	//brain = new Brain();
	std::cout << "\033[34mCalled Dog Constructor and get BRAIN\033[0m" << std::endl; 
}

Dog::Dog(std::string name): Animal(name)
{
	std::cout << "\033[34mCalled Dog with type Constructor\033[0m" << std::endl;
	this->brain = new Brain();
}
Dog::~Dog()
{
	delete brain;
	std::cout << "\033[34mCalled Dog Destructor\033[0m" << std::endl; 
}

Dog::Dog(const Dog& other) : Animal(other), brain(new Brain(*other.brain)) {
	std::cout << "\033[34mCalled Dog Copy Constructor\033[0m" << std::endl; 
}


Dog& Dog::operator=(const Dog& other)
{
	std::cout << "\033[34mCalled Dog  assignment Operator\033[0m" << std::endl; 
	if (this != &other)
	{
		Animal::operator=(other); // copy the type
		delete this->brain;
		this->brain = other.brain ? new Brain(*other.brain) : NULL;
		return (*this);
	}
	//Dog objects should not point to the same Brain object in memory.
	return (*this);
}

std::string Dog::getIdea(int index)
{
	return (this->brain->getIdeas()[index]);
}

void Dog::setIdea(int pos, std::string idea)
{
	this->brain->getIdeas()[pos] = idea;
}

void Dog::makeSound() const
{
	std::cout << "Bark, Bark, Bark! 🐕" << std::endl;
}
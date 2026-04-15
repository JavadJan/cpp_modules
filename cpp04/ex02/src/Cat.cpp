/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhavari <mkhavari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 22:18:55 by mkhavari          #+#    #+#             */
/*   Updated: 2025/09/25 08:36:22 by mkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"

Cat::Cat():AAnimal("Cat") , brain(new Brain()) 
{
	//Call Brain's default constructor to initialize it.
	//It avoids default-initializing brain first, then overwriting it.
	//brain = new Brain();
	std::cout << "\033[33mCalled Cat Cosntructor, and get BRAIN\033[0m" << std::endl; 
}

Cat::Cat(std::string name): AAnimal(name), brain(new Brain())
{
	std::cout << "\033[33mCalled Cat with type Cosntructor\033[0m" << std::endl; 
}
Cat::~Cat()
{
	delete brain;
	std::cout << "\033[33mCalled Cat Decosntructor\033[0m" << std::endl; 
}
Cat::Cat(const Cat& other): AAnimal(other), brain(new Brain(*other.brain))
{
	std::cout << "\033[33mCalled Cat Copy Cosntructor\033[0m" << std::endl; 
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "\033[33mCalled Cat  assignment operator\033[0m" << std::endl; 
	if (this == &other)
		return (*this);
	if (this != &other)
	{
		AAnimal::operator=(other);
		delete this->brain;
		if (other.brain)
			this->brain = new Brain(*other.brain);
		else
			this->brain = NULL;
	}
	return (*this);
}

std::string Cat::getIdea(int index)
{
	return (this->brain->getIdeas()[index]);
}

void Cat::setIdea(int pos, std::string idea)
{
	this->brain->getIdeas()[pos] = idea;
}

void Cat::makeSound() const
{
	std::cout << "Meow, Moew, Meow! 🐈" << std::endl;
}
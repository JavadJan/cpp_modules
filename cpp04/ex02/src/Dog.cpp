/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhavari <mkhavari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 22:18:59 by mkhavari          #+#    #+#             */
/*   Updated: 2025/09/25 08:35:58 by mkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"
#include <stdio.h>
#include <stdlib.h>

Dog::Dog():AAnimal("Dog"), brain(new Brain())
{
	//brain = new Brain();
	std::cout << "\033[34mCalled Dog Cosntructor and get BRAIN\033[0m" << std::endl; 
}

Dog::Dog(std::string name): AAnimal(name), brain(new Brain())
{
	std::cout << "\033[34mCalled Dog with type Cosntructor\033[0m" << std::endl;
}
Dog::~Dog()
{
	delete brain;
	std::cout << "\033[34mCalled Dog Decosntructor\033[0m" << std::endl; 
}

Dog::Dog(const Dog& other) : AAnimal(other),brain(new Brain(*other.brain)) {
	std::cout << "\033[34mCalled Dog Copy Cosntructor\033[0m" << std::endl; 
}


Dog& Dog::operator=(const Dog& other)
{
	std::cout << "\033[33mCalled Dog  assignment operator\033[0m" << std::endl; 
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
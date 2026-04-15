/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhavari <mkhavari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 22:18:03 by mkhavari          #+#    #+#             */
/*   Updated: 2025/09/25 08:12:21 by mkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"
#include <unistd.h>
#include <stdio.h>

Cat::Cat():Animal("Cat") , brain(new Brain()) 
{
	//Call Brain's default constructor to initialize it.
	//It avoids default-initializing brain first, then overwriting it.
	//brain = new Brain();
	std::cout << "\033[33mCalled Default Cat Constructor, and get BRAIN\033[0m" << std::endl; 
}

Cat::Cat(std::string name): Animal(name)
{
	std::cout << "\033[33mCalled Cat with type Constructor\033[0m" << std::endl; 
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
	std::cout << "\033[33mCalled Cat Desttructor\033[0m" << std::endl; 
}
Cat::Cat(const Cat& other): Animal(other), brain(new Brain(*other.brain))
{
	std::cout << "\033[33mCalled Cat Copy Constructor\033[0m" << std::endl; 
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "\033[33mCalled Cat  assignment operator\033[0m" << std::endl; 
	if (this == &other)
		return (*this);
	if (this != &other)
	{
		Animal::operator=(other);
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
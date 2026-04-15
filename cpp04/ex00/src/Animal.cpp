/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhavari <mkhavari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 22:17:12 by mkhavari          #+#    #+#             */
/*   Updated: 2025/09/25 07:08:15 by mkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"

Animal::Animal():type("Animal")
{
	std::cout << "\033[32mCalled Base Animal constructor\033[0m" << std::endl; 
}

Animal::Animal(const std::string &name): type(name)
{
	std::cout << "\033[32mCalled Base Animal with param constructor\033[0m" << std::endl; 
}

Animal::~Animal()
{
	std::cout << "\033[32mCalled Base Animal destructor\033[0m" << std::endl; 
}
Animal::Animal(const Animal& other):type(other.type)
{
	std::cout << "\033[32mCalled Base Animal Copy constructor\033[0m" << std::endl; 
	//*this = other; // called assign copy constructor
}

Animal& Animal::operator=(const Animal& other)
{
	std::cout << "\033[32mCalled Base Animal  assignment operator\033[0m" << std::endl; 
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
	std::cout << "Animal make sound: khoor pooof 🎋️🦁️🐘️🦉️🦢️🎋️" << std::endl;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhavari <mkhavari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 22:17:56 by mkhavari          #+#    #+#             */
/*   Updated: 2025/09/25 07:36:38 by mkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"

Animal::Animal()
{
	std::cout << "\033[32mCalled Base Animal Cosntructor\033[0m" << std::endl; 
}

Animal::Animal(std::string name): type(name)
{
	std::cout << "\033[32mCalled Base Animal with param Cosntructor\033[0m" << std::endl; 
}

Animal::~Animal()
{
	std::cout << "\033[32mCalled Base Animal Decosntructor\033[0m" << std::endl; 
}
Animal::Animal(const Animal& other):type(other.type)
{
	std::cout << "\033[32mCalled Base Animal Copy Cosntructor\033[0m" << std::endl; 
	// *this = other;
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
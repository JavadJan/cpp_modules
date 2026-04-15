/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhavari <mkhavari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 22:17:26 by mkhavari          #+#    #+#             */
/*   Updated: 2025/09/24 22:17:28 by mkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "\033[32mCalled Base WrongAnimal constructor\033[0m" << std::endl; 
}

WrongAnimal::WrongAnimal(const std::string &type) : type(type) 
{
    std::cout << "Base WrongAnimal Constructor with type: " << type << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "\033[32mCalled Base WrongAnimal Deconstructor\033[0m" << std::endl; 
}
WrongAnimal::WrongAnimal(const WrongAnimal& other):type(other.type)
{
	std::cout << "\033[32mCalled Base WrongAnimal Copy constructor\033[0m" << std::endl; 
	// *this = other;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	std::cout << "\033[32mCalled Base WrongAnimal  assignment operator\033[0m" << std::endl; 
	if (this != &other)
	{
		this->type = other.type;
	}
	return (*this);
}

std::string WrongAnimal::getType() const
{
	return this->type;
}

void WrongAnimal::makeSound() const
{
	std::cout << "\033[35mWrongAnimal: khoor pooof" << std::endl;
}

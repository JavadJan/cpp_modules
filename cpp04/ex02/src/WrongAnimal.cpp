/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhavari <mkhavari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 22:19:06 by mkhavari          #+#    #+#             */
/*   Updated: 2025/09/25 08:02:33 by mkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "\033[32mCalled Base WrongAnimal Cosntructor\033[0m" << std::endl; 
}

WrongAnimal::WrongAnimal(std::string name): type(name)
{
	std::cout << "\033[32mCalled Base WrongAnimal with param Cosntructor\033[0m" << std::endl; 
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "\033[32mCalled Base WrongAnimal Decosntructor\033[0m" << std::endl; 
}
WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	std::cout << "\033[32mCalled Base WrongAnimal Copy Cosntructor\033[0m" << std::endl; 
	*this = other;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	std::cout << "\033[32mCalled Base WrongAnimal  assignment Cosntructor\033[0m" << std::endl; 
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
	std::cout << " make sound: khoor pooof 🎋️🦁️🐘️🦉️🦢️🎋️" << std::endl;
}

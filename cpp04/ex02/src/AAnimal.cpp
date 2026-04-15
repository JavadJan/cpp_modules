/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhavari <mkhavari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 22:18:48 by mkhavari          #+#    #+#             */
/*   Updated: 2025/09/25 08:01:41 by mkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AAnimal.hpp"

AAnimal::AAnimal()
{
	std::cout << "\033[32mCalled Base AAnimal Cosntructor\033[0m" << std::endl; 
}

AAnimal::AAnimal(std::string name): type(name)
{
	std::cout << "\033[32mCalled Base AAnimal with param Cosntructor\033[0m" << std::endl; 
}

AAnimal::~AAnimal()
{
	std::cout << "\033[32mCalled Base AAnimal Decosntructor\033[0m" << std::endl; 
}
AAnimal::AAnimal(const AAnimal& other):type(other.type)
{
	std::cout << "\033[32mCalled Base AAnimal Copy Cosntructor\033[0m" << std::endl; 
	// *this = other;
}

AAnimal& AAnimal::operator=(const AAnimal& other)
{
	std::cout << "\033[32mCalled Base AAnimal  assignment Cosntructor\033[0m" << std::endl; 
	if (this != &other)
	{
		this->type = other.type;
	}
	return (*this);
}

std::string AAnimal::getType() const
{
	return this->type;
}

void AAnimal::makeSound() const
{
	std::cout << "khoor pooof" << std::endl;
}
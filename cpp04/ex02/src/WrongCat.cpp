/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhavari <mkhavari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 22:18:17 by mkhavari          #+#    #+#             */
/*   Updated: 2025/09/25 08:39:26 by mkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/WrongCat.hpp"

WrongCat::WrongCat():WrongAnimal("WrongCat"), brain(new Brain())
{
	std::cout << "\033[33mCalled WrongCat Cosntructor\033[0m" << std::endl; 
}

WrongCat::WrongCat(const std::string &name): WrongAnimal(name), brain(new Brain())
{
	std::cout << "\033[33mCalled WrongCat with type Cosntructor\033[0m" << std::endl; 
}
WrongCat::~WrongCat()
{
	delete brain;
	std::cout << "\033[33mCalled WrongCat Decosntructor\033[0m" << std::endl; 
}
WrongCat::WrongCat(const WrongCat& other):WrongAnimal(other), brain(new Brain(*other.brain))
{
	std::cout << "\033[33mCalled WrongCat Copy Cosntructor\033[0m" << std::endl; 
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	std::cout << "\033[33mCalled WrongCat  assignment operator\033[0m" << std::endl; 
	if (this != &other)
	{
		WrongAnimal::operator=(other); // copy the type
		delete this->brain;
		this->brain = other.brain ? new Brain(*other.brain) : NULL;
		return (*this);
	}
	//Dog objects should not point to the same Brain object in memory.
	return (*this);
}

// std::string Cat::getType()
// {
// 	return (this->type);
// }

void WrongCat::makeSound() const
{
	std::cout << "Meow, Moew, Meow! 🐈" << std::endl;
}
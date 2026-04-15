/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhavari <mkhavari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 22:17:16 by mkhavari          #+#    #+#             */
/*   Updated: 2025/09/24 22:17:17 by mkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"

Cat::Cat():Animal("Cat") //must set their type field depending on their name. T
{
	std::cout << "\033[33mCalled Cat Cosntructor\033[0m" << std::endl; 
}

Cat::Cat(std::string name): Animal(name) // must set their type field depending on their name. T
{
	std::cout << "\033[33mCalled Cat with type Cosntructor\033[0m" << std::endl; 
}
Cat::~Cat()
{
	std::cout << "\033[33mCalled Cat Destructor\033[0m" << std::endl; 
}
Cat::Cat(const Cat& other):Animal(other)
{
	std::cout << "\033[33mCalled Cat Copy Cosntructor\033[0m" << std::endl; 
	//*this = other; // called the assign constructor
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "\033[33mCalled Cat  assignment operator\033[0m" << std::endl; 
	if (this != &other)
	{
		this->type = other.type;
	}
	return (*this);
}

//std::string Cat::getType()
//{
//	return (this->type);
//}

void Cat::makeSound() const
{
	std::cout << "Meow, Moew, Meow! 🐈" << std::endl;
}
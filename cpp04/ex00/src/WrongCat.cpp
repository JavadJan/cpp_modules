/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhavari <mkhavari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 22:17:29 by mkhavari          #+#    #+#             */
/*   Updated: 2025/09/25 08:37:47 by mkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/WrongCat.hpp"

WrongCat::WrongCat():WrongAnimal("WrongCat")
{
	std::cout << "\033[33mCalled WrongCat Cosntructor\033[0m" << std::endl; 
}

WrongCat::WrongCat(const std::string &name): WrongAnimal(name)
{
	std::cout << "\033[33mCalled WrongCat with type Cosntructor\033[0m" << std::endl; 
}
WrongCat::~WrongCat()
{
	std::cout << "\033[33mCalled WrongCat Decosntructor\033[0m" << std::endl; 
}
WrongCat::WrongCat(const WrongCat& other):WrongAnimal(other)
{
	std::cout << "\033[33mCalled WrongCat Copy Cosntructor\033[0m" << std::endl; 
	// *this = other;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	std::cout << "\033[33mCalled WrongCat  assignment operator\033[0m" << std::endl; 
	if (this != &other)
	{
		this->type = other.type;
	}
	return (*this);
}

//std::string WrongCat::getType() const
//{
//	return (this->type);
//}

void WrongCat::makeSound() const
{
	std::cout << "WrongCat: !Meow, !Moew, !Meow! 🐈" << std::endl;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhavari <mkhavari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 21:30:05 by mkhavari          #+#    #+#             */
/*   Updated: 2025/09/03 21:30:07 by mkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/Weapon.hpp"

Weapon::Weapon() : type(""){
	std::cout << "called default constructor" << std::endl;
}

Weapon::Weapon(std::string type): type(type)
{
	this->type = type;
	std::cout << "called constructor with parameter" << std::endl;
}
Weapon::~Weapon()
{
	std::cout << "called desctructor" << std::endl;
}

//Weapon::Weapon(const Weapon &other)
//{
//	type = std::string(other.type); 
//	// if type was poiinter of string:
//	// type = new std::string(*other.type);
//}

//Weapon& Weapon::operator=(const Weapon& other) {
//	// prevent self-assignment, this and other should not points to the same object
//    if (this != &other) {  
//        this->type = other.type;  // copy member variables
//    }
//    return *this;  // return current object to allow chaining
//}

std::string Weapon::getType() const
{
	return this->type;
}

void Weapon::setType(std::string type)
{
	this->type = type;
}





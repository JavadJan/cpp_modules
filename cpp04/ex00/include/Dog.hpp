/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhavari <mkhavari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 22:17:00 by mkhavari          #+#    #+#             */
/*   Updated: 2025/09/25 09:46:15 by mkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	DOG_HPP
#define	DOG_HPP
#include "Animal.hpp"
#include <iostream>

class Dog: public Animal
{
	public:
		Dog();
		Dog(std::string type);
		~Dog();
		Dog(const Dog& other);
		Dog& operator=(const Dog& other);
		void makeSound() const ;


};

#endif
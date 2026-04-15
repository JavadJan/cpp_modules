/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhavari <mkhavari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 22:18:34 by mkhavari          #+#    #+#             */
/*   Updated: 2025/09/25 09:46:53 by mkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	DOG_HPP
#define	DOG_HPP
#include "AAnimal.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog: public AAnimal
{
	private:
		Brain *brain;
	public:
		Dog();
		Dog(std::string type);
		~Dog();
		Dog(const Dog& other);
		Dog& operator=(const Dog& other);
		void makeSound() const;

		/* getter */
		std::string getIdea(int index);
		/* setter */
		void setIdea(int pos, std::string idea);
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhavari <mkhavari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 22:18:24 by mkhavari          #+#    #+#             */
/*   Updated: 2025/09/25 08:52:25 by mkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ANIMAL_HPP
#define	ANIMAL_HPP
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define PREV 1
class AAnimal
{
	protected:
		std::string type;
	public:
		AAnimal();
		AAnimal(std::string type);
		virtual ~AAnimal();
		AAnimal(const AAnimal& other);
		AAnimal& operator=(const AAnimal& other);
		virtual void makeSound() const = 0; // if assgin to 0, then it becomes to abstract class
		std::string getType() const;
};
#endif
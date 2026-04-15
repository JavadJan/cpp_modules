/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhavari <mkhavari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 22:16:57 by mkhavari          #+#    #+#             */
/*   Updated: 2025/09/25 09:46:12 by mkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CAT_HPP
#define	CAT_HPP
#include "Animal.hpp"
#include <iostream>

class Cat: public Animal
{
	public:
		Cat();
		Cat(std::string type);
		~Cat();
		Cat(const Cat& other);
		Cat& operator=(const Cat& other);
		void makeSound() const;

		/* getter */
		//std::string getType();
};

#endif
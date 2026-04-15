/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhavari <mkhavari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 22:18:31 by mkhavari          #+#    #+#             */
/*   Updated: 2025/09/25 09:46:40 by mkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CAT_HPP
#define	CAT_HPP
#include "AAnimal.hpp"
#include "Brain.hpp"
#include <iostream>

class Cat: public AAnimal
{
	private:
		Brain *brain;
	public:
		Cat();
		Cat(std::string type);
		~Cat();
		Cat(const Cat& other);
		Cat& operator=(const Cat& other);
		void makeSound() const;

				/* getter */
		std::string getIdea(int index);
		/* setter */
		void setIdea(int pos, std::string idea);
};

#endif
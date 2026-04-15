/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhavari <mkhavari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 22:17:51 by mkhavari          #+#    #+#             */
/*   Updated: 2025/09/25 08:05:46 by mkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	WRONGCAT_HPP
#define	WRONGCAT_HPP
#include "WrongAnimal.hpp"
#include "Brain.hpp"
#include <iostream>

class WrongCat: public WrongAnimal
{
	private:
		Brain *brain;
	public:
		WrongCat();
		WrongCat(const std::string &type);
		~WrongCat();
		WrongCat(const WrongCat& other);
		WrongCat& operator=(const WrongCat& other);
		void makeSound() const;

		/* getter */
		// std::string getType();
};

#endif
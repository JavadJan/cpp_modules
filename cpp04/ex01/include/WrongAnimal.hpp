/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhavari <mkhavari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 22:17:48 by mkhavari          #+#    #+#             */
/*   Updated: 2025/09/24 22:17:49 by mkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef	WRONGANIMAL_HPP
#define	WRONGANIMAL_HPP
#include <iostream>

class WrongAnimal
{
	protected:
		std::string type;
	public:
		WrongAnimal();
		WrongAnimal(const std::string &type);
		virtual ~WrongAnimal();
		WrongAnimal(const WrongAnimal& other);
		WrongAnimal& operator=(const WrongAnimal& other);
		void makeSound() const;
		std::string getType() const;
};
#endif
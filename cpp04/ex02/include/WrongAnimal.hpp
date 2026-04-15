/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhavari <mkhavari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 22:18:37 by mkhavari          #+#    #+#             */
/*   Updated: 2025/09/25 08:32:12 by mkhavari         ###   ########.fr       */
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
		WrongAnimal(std::string type);
		virtual ~WrongAnimal();
		WrongAnimal(const WrongAnimal& other);
		WrongAnimal& operator=(const WrongAnimal& other);
		void makeSound() const;
		std::string getType() const;
};
#endif
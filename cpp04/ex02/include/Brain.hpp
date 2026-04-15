/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhavari <mkhavari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 22:18:28 by mkhavari          #+#    #+#             */
/*   Updated: 2025/09/24 22:18:30 by mkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <iostream>

class Brain
{
	private:
		std::string ideas[100];

	public:
		Brain(); // create new object
		Brain(std::string ideas[]); // create new object
		~Brain();	// delete that object
		Brain(const Brain& other);
		Brain& operator=(const Brain& other);
		std::string *getIdeas();
};

#endif
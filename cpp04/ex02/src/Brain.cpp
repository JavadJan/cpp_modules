/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhavari <mkhavari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 22:18:52 by mkhavari          #+#    #+#             */
/*   Updated: 2025/09/24 22:18:53 by mkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Brain.hpp"

Brain::Brain() 
{
	//Call Brain's default constructor to initialize it.
	//It avoids default-initializing brain first, then overwriting it.
	//brain = new Brain();
	std::cout << "\033[35mCalled Brain Cosntructor, and get BRAIN\033[0m" << std::endl; 
}

Brain::Brain(std::string ideas[])
{
	std::cout << "\033[35mCalled Brain with type Cosntructor\033[0m" << std::endl; 
	for (int i = 0; i < 100; ++i)
    	this->ideas[i] = ideas[i];
}
Brain::~Brain()
{
	std::cout << "\033[35mCalled Brain Decosntructor\033[0m" << std::endl; 
}
Brain::Brain(const Brain& other)
{
	std::cout << "\033[35mCalled Brain Copy Cosntructor\033[0m" << std::endl; 
	//*this = other; // it calls the assigning operator
	 for (int i = 0; i < 100; ++i)
        ideas[i] = other.ideas[i];
}

Brain& Brain::operator=(const Brain& other)
{
	std::cout << "\033[35mCalled Brain  assignment Cosntructor\033[0m" << std::endl; 
	if (this != &other)
	{
		for (int i = 0; i < 100; ++i)
			this->ideas[i].assign(other.ideas[i]);
	}
	return (*this);
}

std::string* Brain::getIdeas()
{
	return (this->ideas);
}
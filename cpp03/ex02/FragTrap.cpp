/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhavari <mkhavari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:16:00 by mkhavari          #+#    #+#             */
/*   Updated: 2026/04/15 21:21:29 by mkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	this->name = "Unknown";
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
	std::cout << "\033[35mDerived Default constructor called\033[0m" << std::endl;
}

FragTrap::FragTrap(std::string name):ClapTrap(name)
{
	// this->name = name;
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
	std::cout << "\033[35mDerived constructor with param called\033[0m" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "\033[35mDerived deconstructor called\033[0m" << std::endl;
}
/* copy constructor */
FragTrap::FragTrap(const FragTrap& other):ClapTrap(other)
{
	std::cout << "Derived copy constructor is called" << std::endl;
}

/* copy assignment construtor */
FragTrap& FragTrap::operator=(const FragTrap& other)
{
	if (this != &other)
	{
		std::cout << "Derived copy assignment constructor called" << std::endl;
		// this->name = other.name;
		// this->attack_damage = other.attack_damage;
		// this->energy_points = other.energy_points;
		// this->hit_points = other.hit_points;
		ClapTrap::operator=(other);
	}
	return (*this);
}

void FragTrap::attack(const std::string& target)
{
	if (this->energy_points <= 0 || this->hit_points <= 0)
    {
		//ClapTrap can’t do anything if it has no hit points or energy points left
        std::cout << "\033[36mFragTrap " << this->name << " can't attack: no energy or dead.\033[0m" << std::endl;
        return;
    }
	std::cout << "FragTrap " << this->name << " attacks " << target
              << ", causing " << this->attack_damage << " points of damage!" << std::endl;
	// attacking const 1 energy
	this->energy_points--;
}

void FragTrap::highFivesGuys()
{
	std::cout << "\033[32mFragTrap " << this->name
              << " requests a high five! ✋😄\033[0m" << std::endl;;
}
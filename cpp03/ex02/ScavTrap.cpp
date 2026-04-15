/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhavari <mkhavari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:16:00 by mkhavari          #+#    #+#             */
/*   Updated: 2026/04/15 21:22:17 by mkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	this->name = "Unknown";
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
	std::cout << "\033[35mDerived Base ScaveTrap constructor\n\033[0m";
}

ScavTrap::ScavTrap(std::string name):ClapTrap(name)
{
	this->name = name;
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
	std::cout << "\033[35mDerived ScaveTrap with params constructor\n\033[0m";
}

ScavTrap::~ScavTrap()
{
	std::cout << "\033[35mDerived ScaveTrap deconstructor\n\033[0m";
}
/* copy constructor */
ScavTrap::ScavTrap(const ScavTrap& other)
{
	std::cout << "ScavTrap copy constructor is called" << std::endl;
	*this = other;
}

/* copy assignment construtor */
ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	if (this != &other)
	{
		std::cout << "ScavTrap Assignation operator called" << std::endl;
		this->name = other.name;
		this->attack_damage = other.attack_damage;
		this->energy_points = other.energy_points;
		this->hit_points = other.hit_points;
	}
	return (*this);
}

void ScavTrap::attack(const std::string& target)
{
	if (this->energy_points <= 0 || this->hit_points <= 0)
    {
		//ClapTrap can’t do anything if it has no hit points or energy points left
        std::cout << "\033[36mScavTrap " << this->name << " can't attack: no energy or dead.\033[0m" << std::endl;
        return;
    }
	std::cout << "\033[32mScavTrap " << this->name << " attacks " << target
              << ", causing " << this->attack_damage << " points of damage!\033[0m" << std::endl;
	// attacking const 1 energy
	this->energy_points--;
}

void ScavTrap::guardGate()
{
	std::cout << "\033[36mScavTrap " << this->name << " is now in Gate keeper mode\033[0m" << std::endl;
}
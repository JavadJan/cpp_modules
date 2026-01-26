#include "ClapTrap.hpp"

ClapTrap::ClapTrap():name(""), hit_points(10), energy_points(10), attack_damage(0)
{
	std::cout << "\033[33mCalled default base constructor\033[0m" << std::endl;
}

ClapTrap::ClapTrap(std::string name):name(name), hit_points(10), energy_points(10), attack_damage(0)
{
	std::cout << "\033[33mCalled base constructor with name\033[0m" << std::endl;
}
ClapTrap::~ClapTrap()
{
	std::cout << "\033[33mCalled base destructor\033[0m" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "Copy Construcotr was called" << std::endl;
	*this = other;
}
int ClapTrap::get_hit_pointes() const
{
	std::cout << "getter for hit points called" << std::endl;
	return this->hit_points;
}
int ClapTrap:: get_energy_points() const
{
	std::cout << "getter for energy points called" << std::endl;
	return this->energy_points;
}
int ClapTrap::get_attack_damage() const{
	std::cout << "getter for attack damage called" << std::endl;
	return this->attack_damage;
}
std::string ClapTrap::get_name() const
{
	std::cout << "getter for name called" << std::endl;
	return this->name;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "copy assignment constructor called" << std::endl;
	if (this != &other)
	{
		this->name = other.get_name();
		this->hit_points = other.get_hit_pointes();
		this->energy_points = other.get_energy_points();
		this->attack_damage = other.get_attack_damage();
	}
	return (*this);
}

void ClapTrap::attack(const std::string& target)
{
	if (this->energy_points <= 0 || this->hit_points <= 0)
    {
		//ClapTrap can’t do anything if it has no hit points or energy points left
        std::cout << "\033[36mClapTrap " << this->name << " can't attack: no energy or dead.\033[0m" << std::endl;
        return;
    }
	std::cout << "\033[30mClapTrap " << this->name << " attacks " << target
              << ", causing " << this->attack_damage << " points of damage!\033[0m" << std::endl;
	// attacking const 1 energy
	this->energy_points--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hit_points <= 0)
    {
		//ClapTrap can’t do anything if it has no hit points or energy points left
        std::cout << "ClapTrap " << this->name << " can't take damage: it is alread dead" << std::endl;
        return;
    }
	std::cout << "ClapTrap " << this->name << " is taking " << amount << " damage!" << std::endl;
	if (amount >= this->hit_points)
		hit_points = 0;
	else
		this->hit_points-= amount;
	if (this->hit_points == 0)
		std::cout << "ClapTrap " << this->name << " has died!" << std::endl;
	//reduce its hit_points, because that represents health.
}

void ClapTrap::beRepaired(unsigned int amount)
{
	//When ClapTrap repairs itself, it regains <amount> hit points.
	if (this->energy_points <= 0 || this->hit_points <= 0)
    {
		//ClapTrap can’t do anything if it has no hit points or energy points left
        std::cout << "ClapTrap " << this->name << " can't repaire: no energy or dead." << std::endl;
        return;
    }
	std::cout << "ClapTrap " << this->name << " is repairing, regain " << amount << " points!" << std::endl;
	//regains <amount> hit points
	if (amount >= this->hit_points)
		hit_points = 0;
	else
		this->hit_points-= amount;
	//repairing lost energy_points
	this->energy_points--;
}


#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
# include "ClapTrap.hpp"

class ScavTrap:public ClapTrap
{
	private:
		std::string name;
	public:
	/*inherit the constructors and destructor from Clap-Trap.*/
	ScavTrap();
	ScavTrap(std::string name);
	~ScavTrap();
	ScavTrap(const ScavTrap& other);
	ScavTrap& operator=(const ScavTrap& other);

	void attack(const std::string& target);
	void guardGate();
};

#endif
#ifndef ZOMBIE_H
#define ZOMBIE_H
#include <iostream>
#include <sstream>

class	Zombie
{
	private:
		std::string name;
	public:
		Zombie();
		~Zombie();
		Zombie(const Zombie& other);             // Copy constructor
    	Zombie& operator =(const Zombie& other); 
		std::string getName();
		void setName(std::string name);
		void announce( void );
};

#endif
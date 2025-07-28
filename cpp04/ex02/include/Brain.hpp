#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <iostream>

class Brain
{
	public:
		std::string ideas[100];
		Brain(); // create new object
		Brain(std::string ideas[]); // create new object
		~Brain();	// delete that object
		Brain(const Brain& other);
		Brain& operator=(const Brain& other);
};

#endif
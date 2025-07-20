#ifndef WAEPON_H
#define WAEPON_H
#include <iostream>

class Weapon
{
	private:
		std::string type;
	public:
		Weapon();
		Weapon(std::string type);
		~Weapon();
		//Weapon(const Weapon& other);             // Copy constructor
		//Weapon& operator =(const Weapon& other);
		std::string getType() const;
		void setType(std::string type);
};

#endif

/*A private attribute type, which is a string.
• A getType() member function that returns a constant reference to type.
• A setType() member function that sets type using the new value passed as a pa*/
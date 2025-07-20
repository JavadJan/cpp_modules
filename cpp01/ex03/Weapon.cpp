#include "Weapon.hpp"

Weapon::Weapon() : type(type){
}

Weapon::Weapon(std::string type)
{
	this->type = type;
}
Weapon::~Weapon()
{

}

//Weapon::Weapon(const Weapon &other)
//{
//	type = std::string(other.type); 
//	// if type was poiinter of string:
//	// type = new std::string(*other.type);
//}

//Weapon& Weapon::operator=(const Weapon& other) {
//	// prevent self-assignment, this and other should not points to the same object
//    if (this != &other) {  
//        this->type = other.type;  // copy member variables
//    }
//    return *this;  // return current object to allow chaining
//}

std::string Weapon::getType() const
{
	return this->type;
}

void Weapon::setType(std::string type)
{
	this->type = type;
}





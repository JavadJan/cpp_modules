#include "../include/Serializer.hpp"
#include <cstdio>

Serializer::Serializer()
{
	// not nead to print any thing because it uninstncable
}
Serializer::~Serializer()
{
	// not nead to print any thing because it uninstncable
}
Serializer::Serializer(const Serializer &other)
{
	// not nead to print any thing because it uninstncable
	(void)other;
}
Serializer &Serializer::operator=(const Serializer &other)
{
	// not nead to print any thing because it uninstncable
	(void)other;
	return (*this);
}

uintptr_t Serializer::serialize(Data *a)
{
	return (reinterpret_cast<uintptr_t>(a));
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

/* first ask question?
	1. what kind of coversion operator exist?
		a)static_cast<> | b)dynamic_cast<> | c)reinterpret_cast<> | c)const_cast<>

	2. how to covert string to char?
		#just convert first char, the whole is not possibel, sizeof(char) != sizeof(string)
	
	3. 
*/
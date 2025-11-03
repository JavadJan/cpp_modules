#ifndef BASE_HPP
#define BASE_HPP
#include <iostream>
#include <ctime>
#include <cstdlib>

class Base {
	public:
		virtual ~Base(); // declaration only
};
Base *generate(void);
void identify(Base* p);
void identify(Base &ref);

#endif

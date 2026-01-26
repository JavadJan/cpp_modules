#include "../include/Base.hpp"

int main()
{
	Base* p = generate();
	identify(p);
	Base &ref = *p;
	identify(ref);
}
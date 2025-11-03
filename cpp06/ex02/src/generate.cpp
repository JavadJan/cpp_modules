#include "../include/Base.hpp"
#include "../include/A.hpp"
#include "../include/B.hpp"
#include "../include/C.hpp"


Base *generate(void) {
    // Seed the random number generator once per program run
    srand(static_cast<unsigned int>(std::time(NULL)));

    int r = rand() % 3; // random number: 0, 1, or 2

    switch (r) {
        case 0:
            std::cout << "Generated A\n";
            return new A();
        case 1:
            std::cout << "Generated B\n";
            return new B();
        default:
            std::cout << "Generated C\n";
            return new C();
    }
}

void identify(Base* p)
{
	try
	{
		if (dynamic_cast<A*>(p))
			std::cout << "A" << std::endl;
		else if (dynamic_cast<B*>(p))
			std::cout << "B" << std::endl;
		else if (dynamic_cast<C*>(p))
			std::cout << "C" << std::endl;
		else
		{
			throw std::runtime_error("Failed to cast");
		}
		/* code */
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}
/*
	derive d; 
	Base *p = &d;
	Drived *pd = dynamic_cast<Derived *>(p); ✅ 
*/

void identify(Base& p)
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "A" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		B &b = dynamic_cast<B &>(p);
		(void)b;
		std::cout << "B" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		C &c = dynamic_cast<C &>(p);
		(void)c;
		std::cout << "C" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

#include <iostream>

class Base
{
	public:
		int x;
		Base(){
			std::cout << "Dfault Constructor\n";
		}
		Base(int f)
		{
			x = f;
			std::cout << "Base Dfault param Constructor\n";
		}
};

class Derived: public Base
{
	private:
		int y;
	public: 

		Derived():Base(y)
		{
			std::cout << "Default Construcotr\n";
		}
		Derived(int c) // here if is not be exist a base default constructor then this one will not work
		{
			y = c;
			std::cout << "derived construtor: this is the real job\n";
		}
};

int main()
{
	Derived d(6);
	return (0);
}
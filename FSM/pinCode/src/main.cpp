#include "../include/Lock.hpp"

int main()
{
	Lock lk;
	lk.install();
	std::cout << "created trafic light\n";
}
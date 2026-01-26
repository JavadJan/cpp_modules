#include <iostream>

typedef std::string text_t; // convert the reserved name into a deserve name
/* another way to define aliase name-> using text_t = std::string; */
typedef int number_t; // number_t technicly is a int

int main()
{
	text_t name;

	name = "javad!";
	std::cout << "hello " << name << std::endl;
	std::cout << "what is your full name " << name << std::endl;
	std::getline(std::cin >> std::ws, name);
	std::cout << "wellcome " + name << std::endl;
	return (0);
}
#include <iostream>

int main()
{
	std::string brain = "HI THIS IS BRAIN";

	std::string *stringPtr = &brain;
	std::string &stringREF = brain;

	//Your program must print:
	//• The memory address of the string variable.
	std::cout << "The memory address of the string variable: " << &brain << std::endl;

	//• The memory address held by stringPTR.
	std::cout << "The memory address held by stringPTR.: " << stringPtr << std::endl;

	//• The memory address held by stringREF.
	std::cout << "The memory address held by stringREF: " << &stringREF << '\n' << std::endl;
	
	//And then:
	//• The value of the string variable.
	std::cout << "The value of the string variable: " << brain << std::endl;

	//• The value pointed to by stringPTR.
	std::cout << "The value pointed to by stringPTR: " << *stringPtr << std::endl;

	//• The value pointed to by stringREF
	std::cout << "The value pointed to by stringREF: " << stringREF << std::endl;

}

/* GOAL: ptr vs refrence
	stringPTR: a pointer to the string.
	stringREF: a reference to the string.

	🔹 Pointer (*)
		Is a variable that stores the memory address of another object.
		Can be null (nullptr).
		Can be reassigned to point to another object.
		Needs explicit dereferencing (*ptr) to access the value.

	Reference (&)
		Is an alias for another object (like a nickname).
		Must be initialized immediately when declared.
		Can never be null.
		Cannot be rebound to another object after initialization.
		Acts like the original variable (no need for * to access).
*/
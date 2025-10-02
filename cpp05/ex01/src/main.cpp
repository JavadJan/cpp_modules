#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"

int main()
{
	
	std::cout << "\033[1;31m\n\nIn the following test: \033[0m" << std::endl;
	std::cout << "\033[1;31m\n\n[TEST 5:] test sign form: \033[0m" << std::endl;
	
	Bureaucrat alice("Alice", 5);
    Bureaucrat bob("Bob", 100);

    Form contract("TopSecretContract", 50 , 50);
	std::cout << contract ;

    alice.signForm(contract);
    bob.signForm(contract);    
}

/* don't catch exception inside the constructor because if cause to finish the constructor
	and creation object happen, how you get that the creation happen? because destructor happen

	[TEST:]
	step 0: create an object
	step 1: creat an object from form
	step 3. appaly bureaucrat on for to apply


	[Unformal Implementation:]
	1. create a Bureaucrat obj e.g., Bureaucrat b("test", 5)
	2. create an Form obj e.g., Form f("rent contract", 6, 6);
	3. f.beSigned(b){b.signForm(*this)} // rentContract is sigend by b

	
*/
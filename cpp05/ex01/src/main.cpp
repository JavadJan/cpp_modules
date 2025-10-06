#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"

int main()
{
	
	std::cout << "\033[1;31m\n\n[TEST 1:] Creation Form: \033[0m" << std::endl;
	try
	{
		Form f0("wrong_grade", 0, 4);
	}
	catch(const std::exception& e)
	{
		std::cout << "Invalid Grade: " << e.what() << '\n';
	}
	
	std::cout << "\033[1;31m\n\n[TEST 2:] Creation Form: \033[0m" << std::endl;
	try
	{
		Form f0("wrong_grade", 4, 0);
	}
	catch(const std::exception& e)
	{
		std::cout << "Invalid Grade: " << e.what() << '\n';
	}

	std::cout << "\033[1;31m\n\n[TEST 3:] test sign form: \033[0m" << std::endl;
	try
	{
		Bureaucrat alice("Alice", 5);
		std::cout << alice << std::endl;

		Bureaucrat bob("Bob", 100);
		std::cout << bob << std::endl;
		
		Form contract("TopSecretContract", 50 , 50);
		std::cout << contract << std::endl;
		alice.signForm(contract);

		// bob should not able to sign because its grade is too low
		bob.signForm(contract);    
	}
	catch(const std::exception& e)
	{
		std::cout << "Invalid Grade: " << e.what() << '\n';
	}
	

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
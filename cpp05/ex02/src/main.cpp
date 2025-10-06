#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"

int main()
{
	
	std::cout << "\033[1;31m\n\n[TEST 1:] test sign form: \033[0m" << std::endl;
	try
	{
		//Bureaucrat alice("Alice", 5);
		Bureaucrat bob("Bob", 100);
		std::cout << bob << std::endl;
		
		Bureaucrat alice("Alice", 100);
		std::cout << alice << std::endl;
		std::cout << std::endl;

    	ShrubberyCreationForm tree("home");
		std::cout << std::endl;
		//std::cout << tree;
		
		std::cout << "alice signs it " << std::endl;
    	tree.beSigned(alice);   // Alice signs it

		std::cout << std::endl;
		std::cout << std::endl;
    	tree.execute(alice); 
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

	bureaucrat.signForm(form): Simulates the bureaucrat’s action of trying to sign a form.

	form.beSigned(bureaucrat): Simulates the form’s internal
 	logic to verify if the bureaucrat has enough grade to sign it
*/
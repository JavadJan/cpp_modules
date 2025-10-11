#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/Intern.hpp"

enum	TestCase
{
	NOT_SIGNED,
	ROBOT,
	SHRUBBERY,
	LEAK,
	ROBOT_TRUE,
	PRESIDENTIAL
};

int	main(void)
{
	TestCase			TEST;

	TEST = PRESIDENTIAL;
	std::cout << "\033[1;31m\n\n[TEST 1:] test sign form: \033[0m" << std::endl;
	try
	{
		std::cout << "[TEST:] creation the intern obj and ist constructor" << std::endl;
		AForm *form;
		Intern x;

		std::string names[3] = {
		"Shrubbery Creation",
		"Presidential Pardon",
		"Robotomy Request",
		};

	
		//ShrubberyCreationForm tree("home");

		std::cout << std::endl;

		switch (TEST)
		{
		case NOT_SIGNED:
		{
			std::cout << "\n\nfirst test with someone who did not sighned!" << std::endl;
			Bureaucrat not_sigend("no_sign", 149);
			std::cout << "		test in loop for all three type form" << std::endl;
			for (size_t i = 0; i < 3; i++)
			{
				form = x.makeForm(names[i] ,"home");
				if (!form)
				{
					printf("Wrong name; Failed creation form\n");
					return 1;
				}
				not_sigend.signForm(*form);
				not_sigend.executeForm(*form);
				std::cout << std::endl;
				delete form;
			}
			break ;
		}
		case ROBOT:{
			std::cout << "\033[1;35m\n\n[TEST ROBOT] without leaks\033[0m" << std::endl;
			Bureaucrat rob("rob", 100);
			for (size_t i = 0; i < 3; i++)
			{
				std::cout<< i << ".  " << std::endl;
				form = x.makeForm(names[i] ,"home");
				if (!form)
				{
					printf("Wrong name; Failed creation form\n");
					return 1;
				}
				rob.signForm(*form);
				rob.executeForm(*form);
				delete form;
				std::cout << std::endl;
			}
			break ;
		}
		case SHRUBBERY:
		{
			std::cout << "\033[1;35m[TEST]alice can not sign tree but bob can \033[0m" << std::endl;
			Bureaucrat bob("Bob", 24);
			for (size_t i = 0; i < 3; i++)
			{
				std::cout<< i << ".  " << std::endl;
				form = x.makeForm(names[i] ,"home");
				if (!form)
				{
					printf("Wrong name; Failed creation form\n");
					return 1;
				}
				bob.signForm(*form);
				bob.executeForm(*form);
				delete form;
				std::cout << std::endl;
			}
			break ;
		}
		case PRESIDENTIAL:{
			std::cout << "\033[1;35m\n\n[TEST] Presidential\033[0m" << std::endl;
			Bureaucrat president("JAVAD", 1);
			for (size_t i = 0; i < 3; i++)
			{
				std::cout<< i << ".  " << std::endl;
				form = x.makeForm(names[i] ,"home");
				if (!form)
				{
					printf("Wrong name; Failed creation form\n");
					return 1;
				}
				president.signForm(*form);
				president.executeForm(*form);
				delete form;
				std::cout << std::endl;
			}
			break ;
		}
		default:
			break ;
		}
	}
	catch (const std::exception &e)
	{
		std::cout << "Invalid Grade: " << e.what() << '\n';
	}
}

/* don't catch exception inside the constructor because if cause to finish the constructor
	and creation object happen,
		how you get that the creation happen? because destructor happen

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
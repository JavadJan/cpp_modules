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

	TEST = NOT_SIGNED;
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
				// catches exception INSIDE → program continues → delete happens
				std::cout << std::endl;
				delete form;
			}
			break ;
		}
		case ROBOT:{
			std::cout << "\033[1;35m\n\n[TEST ROBOT] \033[0m" << std::endl;
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

/* 
	Topic: Factory method pattern + avoiding messy code + more exception handling

	What you learn:

	1. A “factory” pattern (Intern::makeForm)

	You dynamically create forms based on input strings.

	2. Clean alternative to giant if/else

	The assignment forces you to avoid:

	if (name == "robotomy")
	else if (name == "shrubbery")
	else if (name == "pardon")


	You must learn a cleaner, scalable pattern (arrays, structs, pointers to functions, etc.)

	3. Returning pointers and handling unknown forms

	If the name is invalid → print error safely

	If valid → return new form

	4. Exception safety (indirectly)

	Even though makeForm() doesn’t throw by assignment design, you must manage:

	Memory

	Invalid input

	Dynamic creation
*/
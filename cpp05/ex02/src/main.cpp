#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"

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
	AForm *ref;
	// do its job
	std::cout << "\033[1;31m\n\n[TEST 1:] test sign form: \033[0m" << std::endl;
	try
	{

		Bureaucrat bob("Bob", 100);
		std::cout << bob << std::endl;

		Bureaucrat alice("Alice", 147);
		std::cout << alice << std::endl;

		std::cout << std::endl;

		ShrubberyCreationForm tree("home"); 
		std::cout << std::endl;

		switch (TEST)
		{
		case NOT_SIGNED:
		{
			std::cout << "\n\nfirst test with someone who did not sighned!" << std::endl;
			Bureaucrat not_sigend("no_sign", 149);
			not_sigend.signForm(tree);
			not_sigend.executeForm(tree);
			std::cout << std::endl;
			break ;
		}
		case SHRUBBERY:
		{
			std::cout << "\033[1;35m[TEST]alice can not sign tree but bob can \033[0m" << std::endl;
			bob.signForm(tree); // Alice signs it
			bob.executeForm(tree);
			std::cout << std::endl;

			std::cout << "\033[1;35m[TEST]it is turned to Alice: \033[0m" << std::endl;
			alice.signForm(tree); // Alice signs it
			alice.executeForm(tree);
			// here when alice.grade > tree.grade them destroy all object are created in this scope then go to the catch
			std::cout << std::endl;
			std::cout << std::endl;
			break ;
		}
		case ROBOT:{
			std::cout << "\033[1;35m\n\n[TEST] without leaks\033[0m" << std::endl;
			Bureaucrat rob("rob", 100);
			RobotomyRequestForm rr("robot");
			std::cout << rr << std::endl;
			rob.signForm(rr);
			rob.executeForm(rr);
			break ;
		}
			/* code */
		case LEAK:{
			std::cout << "\033[1;35m\n\n[TEST] robotmyRequest: \033[0m" << std::endl;
			Bureaucrat			*robot = new Bureaucrat("robot", 100);
			RobotomyRequestForm	*r = new RobotomyRequestForm("robot");
			std::cout << *r << std::endl;
			robot->signForm(*r);
			robot->executeForm(*r);
			delete robot;
			delete r;
			break ;
			// because if be throwen an Exception before to free memory then cause to mem leak
		}
		case ROBOT_TRUE:{
			std::cout << "\033[1;35m\n\n[TEST] without leaks true to exe\033[0m" << std::endl;
			Bureaucrat rob_true("rob_true", 45);
			RobotomyRequestForm rr("robot");
			std::cout << rr << std::endl;
			rob_true.signForm(rr);
			rob_true.executeForm(rr);
			break ;
		}
		case PRESIDENTIAL:{
			std::cout << "\033[1;35m\n\n[TEST] Presidential\033[0m" << std::endl;
			Bureaucrat pres("JAVAD", 1);
			std::cout << pres << std::endl;
			PresidentialPardonForm pres_form("piece");
			std::cout << pres_form;
			pres.signForm(pres_form);
			std::cout << std::endl;
			pres.executeForm(pres_form);
			std::cout << std::endl;
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
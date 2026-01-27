/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhavari <mkhavari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:43:32 by mkhavari          #+#    #+#             */
/*   Updated: 2025/11/24 15:39:59 by mkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"

enum	TestCase
{
	NOT_SIGNED, 
	ROBOT,
	SHRUBBERY, // create a tree ascii in stream then in file
	LEAK,
	ROBOT_TRUE,
	PRESIDENTIAL
};

int	main(void)
{
	TestCase			TEST;

	TEST = LEAK;
	//AForm *ref;
	// do its job
	std::cout << "\033[1;31m\n\n[TEST 1:] test sign form: \033[0m" << std::endl;
	try
	{

		Bureaucrat bob("Bob", 100);
		std::cout << bob << std::endl;

		Bureaucrat alice("Alice", 147);
		std::cout << alice << std::endl;

		std::cout << std::endl;

		ShrubberyCreationForm tree("home"); // create a form with sign 145 and exec 147
		std::cout << std::endl;

		switch (TEST)
		{
		case NOT_SIGNED:
		{
			std::cout << "\n\n[TEST: ]Create a tree with someone who did not sighned!" << std::endl;
			Bureaucrat A("SOMBODY_DIDNT_SIGNED", 149);

			A.signForm(tree);
			A.executeForm(tree);
			std::cout << std::endl;
			break ;
		}
		case SHRUBBERY:
		{
			std::cout << "\033[1;35m[TEST]alice can not sign tree but bob can \033[0m" << std::endl;
			bob.signForm(tree); // Bob signs it
			bob.executeForm(tree);
			std::cout << tree << std::endl;

			std::cout << "\033[1;35m[TEST]it is turned to Alice: \033[0m" << std::endl;
			alice.signForm(tree); // Alice can't signs it
			std::cout<< tree << std::endl;
			
			alice.executeForm(tree);
			// here when alice.grade > tree.grade them destroy all object are created in this scope then go to the catch
			std::cout << std::endl;
			std::cout << std::endl;
			break ;
		}
		case ROBOT:{
			std::cout << "\033[1;35m\n\n[TEST] without leaks\033[0m" << std::endl;
			Bureaucrat rob("rob", 100); // allocated on stack
			RobotomyRequestForm rr("robot"); // allocated on stack
			std::cout << rr << std::endl;
			rob.signForm(rr);
			rob.executeForm(rr);
			break ;
		}
		case LEAK:{
			std::cout << "\033[1;35m\n\n[TEST] LEAK: robotmyRequest: \033[0m" << std::endl;
			Bureaucrat			*robot = new Bureaucrat("robot", 100); 
			RobotomyRequestForm	*r = new RobotomyRequestForm("robot");
			std::cout << *r << std::endl;
			robot->signForm(*r);
			robot->executeForm(*r);
			delete robot;
			delete r;
			break ;
			//robot and r are allocated with new → on the heap. the obj live until calling delete obj
			//MUST be manually deleted using delete.
			//because if be throwen an Exception before to free memory then cause to mem leak
			//Stack allocation is safer because C++ automatically destroys objects even if an exception occurs.
			//Heap allocation (new/delete) is dangerous unless you use smart pointers like std::unique_ptr.
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

			PresidentialPardonForm pres_form("contract");
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

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	Avoids code duplication
	Each form would otherwise repeat the same checks.
	
	Central logic in one place
	If you change the rule, you change it once.
	
	Cleaner derived classes
	Concrete classes only implement the action, not the checks.
	
	Better object-oriented design (“Template Method” pattern)
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	// -------------------
	1. Abstract classes + exceptions inside them
		AForm is abstract and handles:
			Grades
			Signed status
			execute() with exceptions

	2. Derived classes implement actions
		Each form performs different behavior, but all share the same exception rules.

	3. Where to check exceptions (design choice)
		The assignment purposely tests your ability to design clean code:
		Check in base class = elegant
		Check in derived classes = works, but messy

	4. Throwing exceptions for execution problems
		Not signed → throw
		Grade too low → throw

	5. Bureaucrat executing forms
		executeForm() tries… catches errors… prints result.
*/
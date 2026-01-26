#include "../include/Intern.hpp"
#include "../include/Bureaucrat.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"

// ---------------------------------------------------#
//                                                    #
//                     constructor	                  #
//                                                    #
//----------------------------------------------------#
	
Intern::Intern()
{
	std::cout << "\033[1;33mCalled Intern default constrcutor\033[0m" << std::endl;	
}
		
Intern::~Intern()
{
		std::cout << "\033[1;33mCalled Intern destrcutor\033[0m" << std::endl;	
}
		
Intern& Intern::operator=(const Intern &other)
{
	std::cout << "\033[1;33mCalled Intern assignmrnt operator\033[0m" << std::endl;	
	if (this == &other)
		return (*this);
	return (*this);
}
		
Intern::Intern(const Intern &other)
{
	std::cout << "\033[1;33mCalled copy constrcutor\033[0m" << std::endl;	
	*this = other;
}
// ---------------------------------------------------#
//                                                    #
//                     func pointer	                  #
//                                                    #
//----------------------------------------------------#
AForm* Intern::makeShrubbery(const std::string &targetForm) const
{
 	return new ShrubberyCreationForm(targetForm);
}
AForm* Intern::makePresidential(const std::string &targetForm) const
{
	return new PresidentialPardonForm(targetForm);
}
AForm* Intern::makeRobotomy(const std::string &targetForm) const
{
	return new RobotomyRequestForm(targetForm); 
}

AForm* Intern::makeForm(const std::string &nameForm, const std::string &targetForm)
{
	//1. It returns a pointer to a AForm object (corresponding to the form name passed as a parameter)
	std::string names[] = {
		"Shrubbery Creation",
		"Presidential Pardon",
		"Robotomy Request",
	};
	//Each function returns a pointer to AForm.
	//An array of 3 pointers to member functions of Intern.
	//Each function takes a const std::string& and doesn’t modify the object (const).
	//Initializing the array with addresses of member functions that create each specific form.
	// int* A[3] = {1, 2, 3}
	AForm* (Intern::*formCreator[3])(const std::string &target) const = {&Intern::makeShrubbery, &Intern::makePresidential, &Intern::makeRobotomy};
	//2. target initialized to the second parameter.
	for (int i = 0; i < 3; i++) {
        if (nameForm == names[i]) {
            std::cout << "Intern creates " << nameForm << std::endl;
            return (this->*formCreator[i])(targetForm);
        }
    }
	std::cout << "Intern cannot create form: " << nameForm << std::endl;
	return NULL;
}

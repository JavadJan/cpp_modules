
#ifndef ASHRUBBERYCREATIONFORM_HPP
#define ASHRUBBERYCREATIONFORM_HPP
#include <iostream>
#include "AForm.hpp"
#include <fstream>

class Bureaucrat;

class ShrubberyCreationForm: public AForm{
	private:
		std::string target;
	public:
		/* Constructor */
		ShrubberyCreationForm();
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);

		/* getter */
		std::string getTarget() const;
		/* behaviour */
		void execute(Bureaucrat const & executor) const;
};


std::ostream &operator<<(std::ostream &o, ShrubberyCreationForm const &sh);

// create and execute member function in AForm class and
// virtual execute(Bureaucrat const & executor) const = 0
#endif
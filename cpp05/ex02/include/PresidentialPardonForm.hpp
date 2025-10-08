#ifndef PresidentialPardonForm_hpp
# define PresidentialPardonForm_hpp
# include <iostream>
#include "AForm.hpp"


class Bureaucrat;

class PresidentialPardonForm:public AForm
{
	private:
		std::string target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string &target);
		~PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm &other);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
		/*  getter*/
		std::string getTarget() const;
		/* methods */
		void execute(Bureaucrat const &executor) const;
};

std::ostream &operator<<(std::ostream &o, PresidentialPardonForm const &pr);


#endif
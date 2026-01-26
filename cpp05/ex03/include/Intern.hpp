#ifndef Intern_hpp
# define Intern_hpp
# include <iostream>
#include "./AForm.hpp"

class Intern{
	private:
		AForm* makeShrubbery(const std::string &targetForm) const;
		AForm* makePresidential(const std::string &targetForm) const;
		AForm* makeRobotomy(const std::string &targetForm) const;
	public:
		Intern();
		~Intern();
		Intern& operator=(const Intern &other);
		Intern(const Intern &other);
		AForm* makeForm(const std::string &nameForm, const std::string &targetForm); 
};
#endif
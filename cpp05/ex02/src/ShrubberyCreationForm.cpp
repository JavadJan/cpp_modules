#include "../include/ShrubberyCreationForm.hpp"
#include "../include/Bureaucrat.hpp"
// ---------------------------------------------------#
//                                                    #
//                 Constructor                        #
//                                                    #
//----------------------------------------------------#
ShrubberyCreationForm::ShrubberyCreationForm()
{
	std::cout<< "\033[1;31mCalled defaulr ShrubberyCreationForm onstructor\033[0m" << std::endl;	
}
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout<< "\033[1;31mCalled ShrubberyCreationForm destructor\033[0m" << std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
: AForm("ShrubberyCreationForm", 145, 137), target(target)
{
	std::cout<< "\033[1;31mCalled ShrubberyCreationForm Constructor with param\033[0m" << std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other):AForm(other)
{
	std::cout<< "\033[1;31mCalled copy Constructor\033[0m" << std::endl;
	this->target = other.target;
}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	std::cout<< "\033[1;31mCalled overload operator\033[0m" << std::endl;
	if (this != &other)
	{
		this->target = other.target;
	}
	return (*this);
}

// ---------------------------------------------------#
//                                                    #
//                 Behavoiur	                      #
//                                                    #
//----------------------------------------------------#
void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (!getSigend())
	{
		throw std::runtime_error("Form not signed!");
	}
	if (executor.getGrade() > getGradeExe()) // e.g., 45 > 44
        throw GradeTooLowException();
	std::ofstream ofs(target + "_shrubbery");
	if (!ofs)
		throw std::runtime_error("Could not open file.");
	ofs << "	      ^^\n";
	ofs << "	     ^^v^^\n";
	ofs << "	    ^^ava^^\n";
	ofs << "	   ^^javad^^\n";
	ofs << "	   ^^javad^^\n";
	ofs << "	  ^^^javad^^^\n";
	ofs << "	^^^^^javad^^^^^\n";
	ofs << "  j^a^v^a^d^j^a^v^a^d^\n";
	ofs << " j^a^v^a^d^j^a^v^a^d^^\n";
	ofs << "j^a^v^a^d^j^a^v^a^d^^^^\n";
	ofs << " j^a^v^a^d^j^a^v^a^d^^\n";
	ofs << " j^a^v^a^d^j^a^v^a^d^\n";
	ofs << "    \\ |||| /\n";
	ofs << "	   ||||\n";
	ofs << "       ||||\n";
	ofs << "      /||||\n";
	ofs << "     //java\\\\\n";
	ofs << "    ////java\\\\\\\n";
	ofs << "  ////java\\\\\\\\\\\n";
	std::cout << executor.getName() << " executed " << this->getName() << std::endl;
}
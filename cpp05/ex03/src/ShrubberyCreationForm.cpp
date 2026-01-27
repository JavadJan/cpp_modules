/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhavari <mkhavari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:44:37 by mkhavari          #+#    #+#             */
/*   Updated: 2025/11/24 14:44:45 by mkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ShrubberyCreationForm.hpp"
#include "../include/Bureaucrat.hpp"
// ---------------------------------------------------#
//                                                    #
//                 Constructor                        #
//                                                    #
//----------------------------------------------------#
ShrubberyCreationForm::ShrubberyCreationForm()
{
	std::cout<< "\033[1;31mCalled default ShrubberyCreationForm constructor\033[0m" << std::endl;	
}
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout<< "\033[1;31mCalled ShrubberyCreationForm(" << getName() << ") destructor\033[0m" << std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
: AForm("ShrubberyCreationForm", 145, 137), target(target)
{
	std::cout<< "\033[1;31mCalled ShrubberyCreationForm Constructor with param(145, 137)\033[0m" << std::endl;
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
std::string ShrubberyCreationForm::getTarget() const
{
	return (this->target);
}
// ---------------------------------------------------#
//                                                    #
//                 Behavoiur	                      #
//                                                    #
//----------------------------------------------------#
void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	//if (!getSigend())
	//{
	//	//throw std::runtime_error("Form not signed!");
	//	throw NotSignedException(executor.getName());
	//}
	//if (executor.getGrade() > getGradeExe()) // e.g., 45 > 44
    //    throw GradeTooLowException(executor.getName(), executor.getGrade());
	checkExecution(executor);
	std::ofstream ofs((target + "_shrubbery").c_str());
	if (!ofs)
		throw std::runtime_error("Could not open file.");

	ofs << "	       ^^\n";
	ofs << "	      ^^v^^\n";
	ofs << "	     ^^ava^^\n";
	ofs << "	    ^^javad^^\n";
	ofs << "	   ^^^javad^^\n";
	ofs << "	  ^^^^javad^^^\n";
	ofs << "	^ ^ ^^javad^^ ^ ^\n";
	ofs << "  j^a^v^a^d^j^a^v^a^d^j\n";
	ofs << " j^a^v^a^d^j^a^v^a^d^j^j\n";
	ofs << "j^a^v^a^d^j^a^v^a^d^j^a^j\n";
	ofs << " j^a^v^a^d^j^a^v^a^d^a^j\n";
	ofs << "  j^a^v^a^d^j^a^v^a^d^j\n";
	ofs << "        \\ |||| /\n";
	ofs << "   	      ||||\n";
	ofs << "          ||||\n";
	ofs << "         /||||\n";
	ofs << "        //java\\\\\n";
	ofs << "       ////java\\\\\\\n";
	ofs << "     ////java\\\\\\\\\\\n";
	std::cout << executor.getName() << " executed " << this->getName() << std::endl;
	ofs.close();
}

// ---------------------------------------------------#
//                                                    #
//                 insertion overload	              #
//                                                    #
//----------------------------------------------------#

std::ostream &operator<<(std::ostream &out, ShrubberyCreationForm const &sh)
{
	out << sh.getName() << " with target: (" << sh.getTarget()
	<< "), grade sign " << sh.getGradeSigned() 
	<< " grade execution " << sh.getGradeExe()
	<< " signed=" << (sh.getSigend() ? "true" : "false") << "created " 
	<< sh.getTarget() <<"_shrubbery" << '\n';
	return (out);
}
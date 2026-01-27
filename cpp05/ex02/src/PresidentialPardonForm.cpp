/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhavari <mkhavari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:43:35 by mkhavari          #+#    #+#             */
/*   Updated: 2025/11/24 14:43:37 by mkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PresidentialPardonForm.hpp"
#include "../include/Bureaucrat.hpp"

// ---------------------------------------------------#
//                                                    #
//                     constructor	                  #
//                                                    #
//----------------------------------------------------#
PresidentialPardonForm::PresidentialPardonForm():target("")
{
	std::cout << "\033[1;33mCalled " << getName() << " default constrcutor\033[0m" << std::endl;	
}
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "\033[1;33mCalled " << getName() << " destrcutor\033[0m" << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
:AForm("PresidentialPardonForm", 25, 5), target(target)
{

	std::cout << "\033[1;33mCalled " << getName() << " parameteized constrcutor\033[0m" << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other):AForm(other)
{
	std::cout << "\033[1;33mCalled " << getName() << "copy constrcutor\033[0m" << std::endl;
	this->target = target;
}
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	std::cout << "\033[1;33mCalled overload assignment operator\033[0m" << std::endl;
	if (this != &other)
	{
		this->target = other.target;
	}
	return (*this);
}

// ---------------------------------------------------#
//                                                    #
//                     Methods		                  #
//                                                    #
//----------------------------------------------------#
void	PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	checkExecution(executor);
	std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

// ---------------------------------------------------#
//                                                    #
//                     getter		                  #
//                                                    #
//----------------------------------------------------#
std::string PresidentialPardonForm::getTarget() const
{
	return (this->target);
}
std::ostream &operator<<(std::ostream &out, PresidentialPardonForm const &pr)
{
	out << pr.getName() << " with target: (" << pr.getTarget()
	<< "), grade sign " << pr.getGradeSigned() 
	<< " grade execution " << pr.getGradeExe()
	<< " signed=" << (pr.getSigend() ? "true" : "false") << '\n';
	return (out);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhavari <mkhavari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:42:36 by mkhavari          #+#    #+#             */
/*   Updated: 2025/11/24 14:42:38 by mkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

t_grade Bureaucrat::gradeLimits = {1, 150};
//----------------------------------------------------#
//                                                    #
//                    constructor                     #
//                                                    #
//----------------------------------------------------#
Bureaucrat::Bureaucrat(): name("Default"), grade(150)
{
	std::cout << "\033[1;34mCalled Bureaucrat default constructor\033[0m" << std::endl;
}
Bureaucrat::~Bureaucrat()
{
	std::cout << "\033[1;34mCalled Bureaucrat destructor\033[0m" << std::endl;
}
Bureaucrat::Bureaucrat(const std::string &name, const int grade): name(name), grade(grade) // because the name is constant it should init in initializer
{
	std::cout << "\033[1;34mCalled Bureaucrat constructor with param: " << grade << "\033[0m" << std::endl;
	if (this->grade > this->gradeLimits.max)
	{
		throw GradeTooLowException();
	}
	else if (this->grade < this->gradeLimits.min)
	{
		throw GradeTooHighException();
	}
	// grade was initialized in the initializer list
}
/* 
	⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️
	You throw, but you also catch immediately inside.
	
	That means the exception is handled right there, and construction continues.
	
	So the constructor finishes successfully → you end up with a Bureaucrat object.
	⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️
*/
Bureaucrat::Bureaucrat(const Bureaucrat &other):name(other.name),grade(other.grade)
{
	std::cout << "\033[1;34mCalled copy Bureaucrat constructor\033[0m" << std::endl;
}
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	std::cout << "\033[1;34mCalled assignment Bureaucrat operator\033[0m" << std::endl;
	if (this != &other)
	{
		this->grade = other.grade;
		//this->name = other.name; // name can not assign because this is constant
	}
	return (*this);
}
//----------------------------------------------------#
//                                                    #
//                    getters                         #
//                                                    #
//----------------------------------------------------#
std::string Bureaucrat::getName() const
{
	return (this->name);
}
int	Bureaucrat::getGrade(void) const
{
	return (this->grade);
}

//If the grade goes out of range, both functions must throw the same exceptions as the
//constructor.
//----------------------------------------------------#
//                                                    #
//                    behaviour                       #
//                                                    #
//----------------------------------------------------#
void	Bureaucrat::incrementBureaucrat(void)
{

	if (this->grade <= 1)
		throw GradeTooHighException();
	--grade;
	std::cout << this->name << " promoted congragulation 🥳 " << this->grade << std::endl;	
}
void	Bureaucrat::decreamentBureaucrat(void)
{
	if (grade >= 150)
		throw GradeTooLowException();
	++grade;  // grade goes down in rank
	std::cout << this->name << " demoted " << this->grade << std::endl;
	
}
//----------------------------------------------------#
//                                                    #
//                    rewrite what()                  #
//                                                    #
//----------------------------------------------------#
const char* Bureaucrat::GradeTooHighException::what() const throw() 
{
    return " Grade is out of range (Too High)";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() 
{
    return " Grade is out of range (Too Low)";
}

//----------------------------------------------------#
//                                                    #
//                    overload <<                     #
//                                                    #
//----------------------------------------------------#
std::ostream &operator<<(std::ostream &o, Bureaucrat const &bu)
{
	o << bu.getName() << ", bureaucrat grade " << bu.getGrade() << std::endl;
	return (o);
}

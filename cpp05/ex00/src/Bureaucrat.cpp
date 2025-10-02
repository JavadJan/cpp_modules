#include "../include/Bureaucrat.hpp"

t_grade Bureaucrat::gradeLimits = {1, 150};

Bureaucrat::Bureaucrat()
{
	std::cout << "\033[1;34mCalled Bureaucrat defaault constructor\033[0m]" << std::endl;
}
Bureaucrat::~Bureaucrat()
{
	std::cout << "\033[1;34mCalled Bureaucrat destructor\033[0m" << std::endl;
}
Bureaucrat::Bureaucrat(std::string name, int grade): name(name)// because the name is constant it should init in initilazer
{
	std::cout << "\033[1;34mCalled Bureaucrat constructor with param: " << grade << "\033[0m" << std::endl;
	if (grade > this->gradeLimits.max)
	{
		throw GradeTooHighException();
	}
	else if (grade < this->gradeLimits.min)
	{
		throw GradeTooLowException();
	}
	this->grade = grade;
	std::cout << *this;
	//try
	//{
	//}
	//catch(const std::exception& e)
	//{
	//	std::cout << "Invalid Grade: " << grade << e.what() << '\n';
	//}
}
/* 
	You throw, but you also catch immediately inside.
	
	That means the exception is handled right there, and construction continues.
	
	So the constructor finishes successfully → you end up with a Bureaucrat object.
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
void	Bureaucrat::incrementBureaucrat(void)
{
	//try
	//{
		if (this->grade <= 1)
			throw GradeTooLowException();
		--grade;
		std::cout << this->name << " promoted congragulation 🥳 " << this->grade << std::endl;
	//}
	//catch(const std::exception& e)
	//{
	//	std::cout << "Invalid promotion: " << this->grade - 1 << e.what() << '\n';
	//}
	
}
void	Bureaucrat::decreamentBureaucrat(void)
{
	//try
	//{
		if (grade >= 150)
			throw GradeTooHighException();
		++grade;  // grade goes down in rank
		std::cout << this->name << " demoted " << this->grade << std::endl;
	//}
	//catch(const std::exception& e)
	//{
	//	std::cout << "Invalid demotion: " << this->grade + 1 << e.what() << '\n';
	//}
	
}

const char* Bureaucrat::GradeTooHighException::what() const throw() 
{
    return " Grade is out of range (Too High)";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() 
{
    return " Grade is out of range (Too Low)";
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &bu)
{
	o << bu.getName() << ", bureaucrat grade " << bu.getGrade() << std::endl;
	return (o);
}

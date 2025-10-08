#include "../include/Bureaucrat.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>
// ---------------------------------------------------#
//                                                    #
//                     constructor	                  #
//                                                    #
//----------------------------------------------------#
RobotomyRequestForm::RobotomyRequestForm():target("")
{
	std::cout << "\033[1;33mCalled " << getName() << " default constrcutor\033[0m" << std::endl;	
}
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "\033[1;33mCalled " << getName() << " destrcutor\033[0m" << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
:AForm("RobotomyRequestForm", 72, 45), target(target)
{

	std::cout << "\033[1;33mCalled " << getName() << " parameteized constrcutor\033[0m" << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other):AForm(other)
{
	std::cout << "\033[1;33mCalled " << getName() << "copy constrcutor\033[0m" << std::endl;
	this->target = target;
}
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
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
//                      behaiour	                  #
//                                                    #
//----------------------------------------------------#


void RobotomyRequestForm:: execute(Bureaucrat const &executor) const
{
	checkExecution(executor);
	//std::cout << this->target <<  " has been robotomized successfully 50% of the time." << std::endl;
	srand(time(NULL));
	std::cout << "Brrrr... drilling noises...\n";

    if (rand() % 2)
        std::cout << target << " has been robotomized successfully.\n";
    else
        std::cout << target << " robotomy failed.\n";
}



std::string RobotomyRequestForm::getTarget() const{
	return (this->target);
}





// ---------------------------------------------------#
//                                                    #
//                 insertion overload	              #
//                                                    #
//----------------------------------------------------#

std::ostream &operator<<(std::ostream &out, RobotomyRequestForm const &sh)
{
	out << sh.getName() << " with target: (" << sh.getTarget()
	<< "), grade sign " << sh.getGradeSigned() 
	<< " grade execution " << sh.getGradeExe()
	<< " signed=" << (sh.getSigend() ? "true" : "false") << '\n';
	return (out);
}
#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"


// ---------------------------------------------------#
//                                                    #
//                 Constructor                        #
//                                                    #
//----------------------------------------------------#
AForm::AForm()
: name("default")      // or any default string
, grade_signed(0)      // must give a value
, grade_exe(0)         // must give a value
, sign(false)
{
	std::cout << "\033[1;33mCalled AForm default constructor\033[0m" << std::endl;
}

AForm::AForm(const std::string &name,const  int grade_signed,const  int grade_exe)
: name(name)
, grade_signed(grade_signed)
, grade_exe(grade_exe)
, sign(false)
{
    std::cout << "\033[1;33mCalled AForm params constructor\033[0m" << std::endl;
	if (grade_exe < 1)
	{
		throw GradeTooHighException(name, grade_exe);
	}
	if (grade_signed < 1)
	{
		throw GradeTooHighException(name, grade_signed);
	}

	if (grade_exe > 150)
	{
		throw GradeTooLowException(name, grade_exe);
	}
	if (grade_signed > 150)
	{
		throw GradeTooLowException(name, grade_signed); // 150 is lower than 1
	}
	//std::cout << *this;	
}

AForm::AForm(const AForm& other)
:name(other.name)
, grade_signed(other.grade_signed)
, grade_exe(other.grade_exe)
, sign(other.sign)
{
	std::cout << "\033[1;33mCalled AForm copy constructor\033[0m" << std::endl;
}

AForm& AForm::operator=(const AForm& other) // attribute are const, can be assign
{
	std::cout << "\033[1;33mCalled assigned overload oparator\033[0m" << std::endl;
	if (this != &other)
	{
		//this->name = other.name;
		//this->grade_exe = other.grade_exe;
	}
	return (*this);
}

AForm::~AForm()
{
	std::cout << "\033[1;33mCalled AForm destructor\033[0m" << std::endl;
}


/* ~~~~~~~~~~~~~~~~~~~~ Exceptions ~~~~~~~~~~~~~~~~~~~#
													  # 
                                                      # 
                                                      # 
                                                      # 
   ~~~~~~~~~~~~~~~~~~~~ Exceptions ~~~~~~~~~~~~~~~~~~~#
*/
AForm::GradeTooHighException::GradeTooHighException(const std::string &name, int grade)
{
	std::stringstream ss;
    ss << grade;           // insert the int into the stringstream
    std::string str_grade = ss.str();
	err_msg = name + "': grade too high (" + str_grade + ")";
}

AForm::GradeTooLowException::GradeTooLowException(const std::string &name, int grade)
{
	std::stringstream ss;
    ss << grade;           // insert the int into the stringstream
    std::string str_grade = ss.str();
	err_msg = name + "': grade too low (" + str_grade + ")";
}
const char* AForm::GradeTooHighException::what() const throw()
{
	return (err_msg.c_str()); // convert std::string to the const char*
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return (err_msg.c_str());
}
AForm::GradeTooLowException::~GradeTooLowException() throw()
{
	std::cout << "\033[1;31m Called GradeTooHighException destructor\033[0m" << std::endl;
}
AForm::GradeTooHighException::~GradeTooHighException() throw()
{
	std::cout << "\033[1;31m Called GradeTooLowException destructor\033[0m" << std::endl;	
}

AForm::NotSignedException::NotSignedException(std::string const &nameBu)
    : err_signed(nameBu + " \033[31mdid not signed the Form\033[0m") {}
const char *AForm::NotSignedException::what() const throw()
{
	return (this->err_signed.c_str());
}
AForm::NotSignedException::~NotSignedException() throw()
{
	std::cout << "\033[1;31m Called NotSignedEception destructor\033[0m" << std::endl;	
}
//----------------------------------------------------#
//                                                    #
//                    getters                         #
//                                                    #
//----------------------------------------------------#
std::string AForm::getName() const
{
	return (this->name);
}
int AForm::getGradeSigned() const
{
	return (this->grade_signed);
}

int AForm::getGradeExe() const
{
	return (this->grade_exe);
}
bool AForm::getSigend() const
{
	return (this->sign);
}
//----------------------------------------------------#
//                                                    #
//                    behaves                         #
//                                                    #
//----------------------------------------------------#

void AForm::beSigned(Bureaucrat &b)
{
	if (b.getGrade() <= this->grade_exe) // if person has grade 1 then can sign AForm with grade 2
	{// person with grade 2 can not sign form with grade 1
		this->sign = true;
		//b.signForm(*this); // A person sign a form and form.sign => true
	}
	else
	{
		throw GradeTooLowException(b.getName(), b.getGrade()); // not qualified to sign
	}
}

void AForm::checkExecution(Bureaucrat const &executor) const {
    if (!this->sign)
        throw NotSignedException(this->name);
    if (executor.getGrade() > this->grade_exe)
        throw GradeTooLowException(executor.getName(), executor.getGrade());
}

//----------------------------------------------------#
//                                                    #
//                    Overload                        #
//                                                    #
//----------------------------------------------------#
std::ostream& operator<<(std::ostream& os, AForm const &form)
{
	os << form.getName() 
		<< ", grade sign " << form.getGradeSigned() 
		<< " grade execution " << form.getGradeExe()
		<< " signed=" << (form.getSigend() ? "true" : "false") << '\n';
	return (os);
}
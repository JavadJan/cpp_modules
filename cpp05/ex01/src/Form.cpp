#include "../include/Form.hpp"
#include "../include/Bureaucrat.hpp"


// ---------------------------------------------------#
//                                                    #
//                 Constructor                        #
//                                                    #
//----------------------------------------------------#
Form::Form()
: name("default")      // or any default string
, grade_signed(0)      // must give a value
, grade_exe(0)         // must give a value
, sign(false)
{
	std::cout << "\033[1;33mCalled Form default constructor\033[0m" << std::endl;
}

Form::Form(std::string name, int grade_signed, int grade_exe)
: name(name)
, grade_signed(grade_signed)
, grade_exe(grade_exe)
, sign(false)
{
    std::cout << "\033[1;33mCalled Form params constructor\033[0m" << std::endl;
	if (grade_exe < 1)
		throw GradeTooHighException();
	if (grade_signed < 1)
		throw GradeTooHighException();

	if (grade_exe > 150)
		throw GradeTooLowException();
	if (grade_signed > 150)
		throw GradeTooLowException(); // 150 is lower than 1
	std::cout << *this;	
}

Form::Form(const Form& other)
:name(other.name)
, grade_signed(other.grade_signed)
, grade_exe(other.grade_exe)
, sign(other.sign)
{
	std::cout << "\033[1;33mCalled Form copy constructor\033[0m" << std::endl;
}

Form& Form::operator=(const Form& other) // attribute are const, can be assign
{
	std::cout << "\033[1;33mCalled assigned overload oparator\033[0m" << std::endl;
	if (this != &other)
	{
		//this->name = other.name;
		//this->grade_exe = other.grade_exe;
	}
	return (*this);
}

Form::~Form()
{
	std::cout << "\033[1;33mCalled Form destructor\033[0m" << std::endl;
}


/* ~~~~~~~~~~~~~~~~~~~~ Exceptions ~~~~~~~~~~~~~~~~~~~#
													  # 
                                                      # 
                                                      # 
                                                      # 
   ~~~~~~~~~~~~~~~~~~~~ Exceptions ~~~~~~~~~~~~~~~~~~~#
*/
const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade is out of range (Too High)");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade is out of range (Too Low)");
}
//----------------------------------------------------#
//                                                    #
//                    getters                         #
//                                                    #
//----------------------------------------------------#
std::string Form::getName() const
{
	return (this->name);
}
int Form::getGradeSigned() const
{
	return (this->grade_signed);
}

int Form::getGradeExe() const
{
	return (this->grade_exe);
}
bool Form::getSigend() const
{
	return (this->sign);
}
//----------------------------------------------------#
//                                                    #
//                    behaves                         #
//                                                    #
//----------------------------------------------------#

void Form::beSigned(Bureaucrat &b)
{
	if (b.getGrade() < this->grade_exe) // if person has grade 1 then can sign form with grade 2
	{// person with grade 2 can not sign form with grade 1
		this->sign = true;
		//b.signForm(*this); // A person sign a form and form.sign => true
	}
	else
	{
		throw GradeTooLowException(); // not qualified to sign
	}
}

//----------------------------------------------------#
//                                                    #
//                    Overload                        #
//                                                    #
//----------------------------------------------------#
std::ostream& operator<<(std::ostream& os, Form const &form)
{
	os << form.getName() 
		<< ", grade sign " << form.getGradeSigned() 
		<< " grade execution " << form.getGradeExe()
		<< " signed=" << (form.getSigend() ? "true" : "false") << '\n';
	return (os);
}
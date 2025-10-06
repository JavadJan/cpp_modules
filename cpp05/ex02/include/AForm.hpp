//• A constant name.
//• A boolean indicating whether it is signed (at construction, it is not).
//• A constant grade required to sign it.
//• A constant grade required to execute it.
//All these attributes are private, not protected.

#ifndef AForm_HPP
#define AForm_HPP
#include <iostream>


class Bureaucrat;

class AForm{
	private:
		const std::string name;
		const int grade_signed;
		const int grade_exe;
		bool sign;
	public: 
		/* constructors */
		AForm(); // do we nead?
		virtual ~AForm();
		AForm(const std::string &name, const int grade_signed, const int grade_exe);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);

		/* getters */
		std::string getName() const;
		int getGradeSigned() const;
		int getGradeExe() const;
		bool getSigend() const;

		/* behavies */
		void beSigned(Bureaucrat &b);
		virtual void execute(Bureaucrat const & executor) const = 0;

		/* derived exception class && throw */
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};


std::ostream &operator<<(std::ostream &o, AForm const &AForm);

#endif
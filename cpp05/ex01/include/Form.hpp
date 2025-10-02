//• A constant name.
//• A boolean indicating whether it is signed (at construction, it is not).
//• A constant grade required to sign it.
//• A constant grade required to execute it.
//All these attributes are private, not protected.

#ifndef Form_HPP
#define Form_HPP
#include <iostream>


class Bureaucrat;

class Form{
	private:
		const std::string name;
		const int grade_signed;
		const int grade_exe;
		bool sign;
	public: 
		/* constructors */
		Form(); // do we nead?
		~Form();
		Form(std::string name, int grade_signed, int grade_exe);
		Form(const Form& other);
		Form& operator=(const Form& other);

		/* getters */
		std::string getName() const;
		int getGradeSigned() const;
		int getGradeExe() const;
		bool getSigend() const;

		/* behavies */
		void beSigned(Bureaucrat &b);

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


std::ostream &operator<<(std::ostream &o, Form const &form);

#endif
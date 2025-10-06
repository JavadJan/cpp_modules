#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class AForm;

typedef struct Grade {
	int min;
	int max;
} t_grade ;

class Bureaucrat{
	private:
		const std::string name;
		static t_grade gradeLimits; // static, because it keeps the values last number
		int grade;
	public:
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(const std::string &name,const int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);

		/* getters */
		std::string getName() const;
		int getGrade() const;
		void signForm(AForm &f);
		/* behaives */
		void incrementBureaucrat();
		void decreamentBureaucrat(); // it is static, because this func access to the static the var
		//void signForm(Form &f);

		/* derived exception class */
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
std::ostream &operator<<(std::ostream &o, Bureaucrat const &bu);

#endif
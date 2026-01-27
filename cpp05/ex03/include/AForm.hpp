/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhavari <mkhavari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:43:48 by mkhavari          #+#    #+#             */
/*   Updated: 2025/11/24 14:43:49 by mkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//• A constant name.
//• A boolean indicating whether it is signed (at construction, it is not).
//• A constant grade required to sign it.
//• A constant grade required to execute it.
//All these attributes are private, not protected.

#ifndef AForm_HPP
#define AForm_HPP
#include <iostream>
#include <string>
#include <sstream>

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
		void checkExecution(Bureaucrat const &executor) const;
		/* derived exception class && throw */
		class GradeTooHighException : public std::exception
		{
			private:
				std::string err_msg;
			public:
				GradeTooHighException(const std::string &name, int grade);
				virtual ~GradeTooHighException() throw();
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			private:
				std::string err_msg;
			public:
				GradeTooLowException(const std::string &name, int grade);
				virtual ~GradeTooLowException() throw();
				const char* what() const throw();
		};

		class NotSignedException : public std::exception
		{
			private:
				std::string err_signed;
			public:
				NotSignedException(std::string const &nameBu);
				virtual ~NotSignedException() throw();
				const char* what() const throw();
		};
};


std::ostream &operator<<(std::ostream &o, AForm const &AForm);

#endif
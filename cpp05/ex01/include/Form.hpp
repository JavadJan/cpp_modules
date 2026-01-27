/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhavari <mkhavari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:42:49 by mkhavari          #+#    #+#             */
/*   Updated: 2025/11/24 14:42:53 by mkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//• A constant name.
//• A boolean indicating whether it is signed (at construction, it is not).
//• A constant grade required to sign it.
//• A constant grade required to execute it.
//All these attributes are private, not protected.

#ifndef Form_HPP
#define Form_HPP
#include <iostream>

//tell the compiler “this type exists” without pulling in the full header.
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
		Form(const std::string &name, const int grade_signed, const int grade_exe);
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

/*
Bureaucrat needs to know about Form.

Form needs to know about Bureaucrat. 
*/



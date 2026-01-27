/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhavari <mkhavari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:42:27 by mkhavari          #+#    #+#             */
/*   Updated: 2025/11/24 14:42:33 by mkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

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
		Bureaucrat(); // do we nead?
		~Bureaucrat();
		Bureaucrat(const std::string &name,const int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		std::string getName() const;
		int getGrade() const;
		
		void incrementBureaucrat();
		void decreamentBureaucrat(); // it is static, because this func access to the static the var
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
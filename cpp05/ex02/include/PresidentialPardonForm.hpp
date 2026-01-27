/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhavari <mkhavari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:43:15 by mkhavari          #+#    #+#             */
/*   Updated: 2025/11/24 14:43:16 by mkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PresidentialPardonForm_hpp
# define PresidentialPardonForm_hpp
# include <iostream>
#include "AForm.hpp"


class Bureaucrat;

class PresidentialPardonForm:public AForm
{
	private:
		std::string target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string &target);
		~PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm &other);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
		/*  getter*/
		std::string getTarget() const;
		/* methods */
		void execute(Bureaucrat const &executor) const;
};

std::ostream &operator<<(std::ostream &o, PresidentialPardonForm const &pr);


#endif
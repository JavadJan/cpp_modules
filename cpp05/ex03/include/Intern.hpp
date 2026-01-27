/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhavari <mkhavari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:43:54 by mkhavari          #+#    #+#             */
/*   Updated: 2025/11/24 14:43:56 by mkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Intern_hpp
# define Intern_hpp
# include <iostream>
#include "./AForm.hpp"

class Intern{
	private:
		AForm* makeShrubbery(const std::string &targetForm) const;
		AForm* makePresidential(const std::string &targetForm) const;
		AForm* makeRobotomy(const std::string &targetForm) const;
	public:
		Intern();
		~Intern();
		Intern& operator=(const Intern &other);
		Intern(const Intern &other);
		AForm* makeForm(const std::string &nameForm, const std::string &targetForm); 
};
#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhavari <mkhavari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:43:18 by mkhavari          #+#    #+#             */
/*   Updated: 2025/11/24 14:43:19 by mkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RobotomyRequestForm_hpp
# define ROBOTOMYREQUESTFORM_hpp

# include "AForm.hpp"
# include <iostream>

class	Bureaucrat;

class RobotomyRequestForm : public AForm
{
  private:
	std::string target;

  public:
	/* Constructor */
	RobotomyRequestForm();
	~RobotomyRequestForm();
	RobotomyRequestForm(const std::string &target);
	RobotomyRequestForm(const RobotomyRequestForm &other);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

	/* getter */
	std::string getTarget() const;
	 
	/* behaviour */
	void execute(Bureaucrat const &executor) const;
};

std::ostream &operator<<(std::ostream &o, RobotomyRequestForm const &sh);

// create and execute member function in AForm class and
// virtual execute(Bureaucrat const & executor) const = 0
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhavari <mkhavari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 21:29:50 by mkhavari          #+#    #+#             */
/*   Updated: 2025/09/03 21:29:52 by mkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	std::string brain = "HI THIS IS BRAIN";

	std::string *stringPtr = &brain;
	std::string &stringREF = brain;

	//Your program must print:
	//• The memory address of the string variable.
	std::cout << "address of string var: " << &brain << std::endl;

	//• The memory address held by stringPTR.
	std::cout << "address of string stringPtr: " << stringPtr << std::endl;

	//• The memory address held by stringREF.
	std::cout << "address of string stringREf: " << &stringREF << '\n' << std::endl;
	
	//And then:
	//• The value of the string variable.
	std::cout << "value of string string: " << brain << std::endl;

	//• The value pointed to by stringPTR.
	std::cout << "value of string stringPtr: " << *stringPtr << std::endl;

	//• The value pointed to by stringREF
	std::cout << "value of string stringREF: " << stringREF << std::endl;

}
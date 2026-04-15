/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhavari <mkhavari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 15:18:05 by mkhavari          #+#    #+#             */
/*   Updated: 2025/09/03 15:18:07 by mkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PHONEBOOK_H
#define PHONEBOOK_H
#include <iostream>
#include "Contact.hpp"
#include <iomanip>
#include <cstdlib>
#include <sstream>

class PhoneBook
{
	private:
		Contact contact[8];
		int count;
	public:
		PhoneBook();
  		PhoneBook(Contact contact[]);
		~PhoneBook();
		void add(Contact contact, int count);
		void search();
		int exit_();
		//Contact []getContact(){return Contact[]};
};

std::string get_value(std::string msg);
#endif


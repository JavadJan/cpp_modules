#ifndef	PHONEBOOK_H
#define PHONEBOOK_H
#include <iostream>
#include "Contact.hpp"
#include <iomanip>
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
		int exit();
		//Contact []getContact(){return Contact[]};
};

std::string get_value(std::string msg);
#endif


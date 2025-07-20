#ifndef CONTACT_H
# define CONTACT_H

# include <iostream>
class Contact
{
	private:
		std::string name;
		std::string l_name;
		std::string nickname;
		std::string secret;
		std::string phone_num;
		int index;

	public:
		Contact();
		Contact(std::string name, std::string l_name, std::string nickname,
			std::string phone_num, std::string secret, int index);
		~Contact();
		std::string getName() const;
    	std::string getLastName() const;
		std::string getNickname() const;
		std::string getPhoneNumber() const ;
		int getIndex() const;
};

#endif

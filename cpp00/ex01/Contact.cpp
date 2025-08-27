#include "./include/Contact.hpp"

Contact::Contact(std::string name, std::string l_name, std::string nickname,
	std::string phone_num, std::string secret, int index)
{
	this->name = name;
	this->l_name = l_name;
	this->nickname = nickname;
	this->phone_num = phone_num;
	this->secret = secret;
	this->index = (index - 1) - (8 * ((index - 1) / 8));
}

Contact::~Contact() {
}

Contact::Contact() :
    name(""),
    l_name(""),
    nickname(""),
    secret(""),
    phone_num(""),
    index(0)
{}

std::string Contact::getName() const { return this->name; }
std::string Contact::getLastName() const { return this->l_name; }
std::string Contact::getNickname() const { return this->nickname; }
std::string Contact::getPhoneNumber() const { return this->phone_num; }
int Contact::getIndex() const { return this->index;}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhavari <mkhavari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 15:18:13 by mkhavari          #+#    #+#             */
/*   Updated: 2025/09/03 15:18:16 by mkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
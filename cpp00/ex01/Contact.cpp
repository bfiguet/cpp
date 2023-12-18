/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 12:43:07 by bfiguet           #+#    #+#             */
/*   Updated: 2023/12/13 15:54:40 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(){} //Constructeur
Contact::~Contact(){} //Destructeur

void Contact::set_contact(int i)
{
	std::string str;

	this->_i = i;
	std::cout << "Please input your first name : ";
	std::getline(std::cin, str);
	this->_first_name = str;
	std::cout << "Please input your last name : ";
	std::getline(std::cin, str);
	this->_last_name = str;
	std::cout << "Please input your nickname : ";
	std::getline(std::cin, str);
	this->_nickname = str;
	std::cout << "Please input your phone number : ";
	std::getline(std::cin, str);
	this->_phone_num = str;
	std::cout << "Please input your darkest secret for greater security : ";
	std::getline(std::cin, str);
	this->_darkest_secret = str;
	if (_first_name.empty() || _last_name.empty() || _nickname.empty()
		|| _phone_num.empty() || _darkest_secret.empty())
		std::cout<< "Contact not set sorry, retry please." << std::endl << std::endl;
	else
		std::cout << "Contact is saved, thank you!" << std::endl << std::endl;
}

int Contact::is_exist()const
{
	if (this->_first_name.empty() || this->_last_name.empty() || this->_nickname.empty()
		|| this->_phone_num.empty() || this->_darkest_secret.empty())
	{
		std::cout << " Not set yet" << std::endl << std::endl;
		return 1;
	}
	return 0;
}

void Contact::print_contact()const
{
	if (this->_first_name.empty() || this->_last_name.empty() || this->_nickname.empty()
		|| this->_phone_num.empty() || this->_darkest_secret.empty())
	{
		return ;
	}
	std::cout << " | " << std::setw(10) << this->_i;
	std::cout << " | " << std::setw(10) << _print_10(this->_first_name) << ".";
	std::cout << " | " << std::setw(10) << _print_10(this->_last_name) << ".";
	std::cout << " | " << std::setw(10) << _print_10(this->_nickname) << ".";
	std::cout << " | " << std::endl;
	std::cout << std::endl;
}

int Contact::print_list()const
{
	if (_first_name.empty() || _last_name.empty() || _nickname.empty()
		|| _phone_num.empty() || _darkest_secret.empty())
	{
		std::cout<< "No contact yet" << std::endl;
		return 1;
	}
	std::cout<< "Contact num " << this->_i << std::endl;
	std::cout<< "first name : " << this->_first_name << std::endl;
	std::cout<< "last name :  " << this->_last_name << std::endl;
	std::cout<< "nickname : " << this->_nickname << std::endl;
	std::cout<< "phone number : " << this->_phone_num << std::endl;
	std::cout<< "darkest secret : " << this->_darkest_secret << std::endl;
	std::cout << std::endl;
	return 0;
}

std::string Contact::_print_10(std::string str) const
{
	if (str.size() > 10)
		return str.substr(0, 9);
	return str;
}

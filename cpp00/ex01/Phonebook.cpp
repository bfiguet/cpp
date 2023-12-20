/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 12:35:55 by bfiguet           #+#    #+#             */
/*   Updated: 2023/12/13 15:59:58 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook(){} //Constructeur
Phonebook::~Phonebook(){} //Destructeur

void Phonebook::run_phonebook()
{
	std::string str;

	std::cout << std::endl;
	std::cout << "Hello! Welcome on my Phonebook!" << std::endl;
	std::cout << " You can use keywords ADD, SEARCH and EXIT" << std::endl << std::endl;
	std::cout << "> What would you want to do? ";
	while (1)
	{
		getline(std::cin, str);
		if (std::cin.eof())
			return;
		if (str == "ADD")
			Phonebook::_add();
		else if (str == "SEARCH")
			Phonebook::_search();
		else if (str == "EXIT")
			break;
	}
}

void Phonebook::_add()
{
	static int	i;

	this->Contact_list[i % 8].set_contact(i % 8);
	i++;
	std::cout << "> What would you want to do? ";
}

void Phonebook::_search()
{
	int	i;
	int	new_i;
	int	flag;

	i = 0;
	flag = 0;
	new_i = -1;
	std::cout << std::endl;
	std::cout << " | " << std::setw(10) << "Index";
	std::cout << " | " << std::setw(10) << "First name";
	std::cout << " | " << std::setw(10) << "Last name";
	std::cout << " | " << std::setw(10) << "Nickname";
	std::cout << " | " << std::endl;
	std::cout << std::endl;
	while (i < 8)
	{
		if (i == 0 && Contact_list[0].is_exist() == 1)
		{
			flag = 1;
			break ;
		}
		else
			Contact_list[i].print_contact();
		i++;
	}
	std::cout << std::endl;
	if (flag != 1)
	{
		std::cout << "Please enter index of the contact would you wish to display from 0 to 7 : " << std::endl;
		std::cin >> new_i;
		if (std::cin.good() && (new_i >= 0 && new_i <= 7))
			Contact_list[new_i].print_list();
		else
		{
			std::cin.clear();
			std::cout << "Invalid number" << std::endl << std::endl;
		}
	}
	std::cout << "> What would you want to do? ";
}

int	main(void)
{
	Phonebook	phonebook;
	phonebook.run_phonebook();
	return 0;
}

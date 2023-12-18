/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:05:38 by bfiguet           #+#    #+#             */
/*   Updated: 2023/12/13 13:44:22 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACTS_HPP
# define CONTACTS_HPP

#include <string>
#include <iostream>
#include <iomanip>

/*
	class T
	{
		public:
			T (); // Constructeur par défaut
			T (const T&); // Constructeur de recopie
			~T (); // Destructeur éventuellement virtuel
			T &operator=(const T&); // Operator d'affectation
	};
*/

class Contact
{
	public:
		Contact();
		~Contact();
		void	set_contact(int i);
		int		is_exist()const;
		void	print_contact() const;
		int		print_list()const;

	private:
		int			_i;	
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nickname;
		std::string _phone_num;
		std::string	_darkest_secret;
		std::string	_print_10(std::string str)const;		
};

#endif
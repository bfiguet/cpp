/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:04:11 by bfiguet           #+#    #+#             */
/*   Updated: 2023/12/13 16:00:09 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define HONEBOOK_HPP

#include <iostream>
#include "Contact.hpp"
#include <string>
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

class Phonebook
{
	public:
		Phonebook();
		~Phonebook();
		void	run_phonebook();

	private:
		Contact	Contact_list[8];
		void	_add();
		void	_search();
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:54:47 by bfiguet           #+#    #+#             */
/*   Updated: 2023/12/20 14:15:42 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

//CLASSE CANONIQUE:
//	constructeur par defaut
//	constructeur par copie
//	operator d'assignation
//	et destructeur virtuel

class Fixed
{
private:
	int _n;
	static const int _bit = 8;
public:
	Fixed();
	Fixed(Fixed const & rhs);
	Fixed & operator=(Fixed const & rhs);
	~Fixed();
	int	getRawBits()const;
	void setRawBits(int const raw);
};


#endif
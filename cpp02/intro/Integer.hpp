/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Integer.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:08:02 by bfiguet           #+#    #+#             */
/*   Updated: 2023/12/18 18:27:15 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTEGER_HPP
#define INTEGER_HPP

#include <string>
#include <iostream>

class Integer
{
private:
	int _n;
public:
	Integer(int const n);
	~Integer();

	int getVal()const;//acceseur
	Integer& operator=(Integer const & rhs);//surcharge operateur assignation
	Integer	operator+(Integer const & rhs) const; //surcharge operateur d'addition
	//rhs right on side
};

std::ostream & operator<<(std::ostream & o, Integer const & rhs);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Integer.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:10:23 by bfiguet           #+#    #+#             */
/*   Updated: 2023/12/18 18:40:21 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Integer.hpp"

Integer::Integer(int const n): _n(n)
{
	std::cout << "Constructor is called: " << _n << std::endl;
}

Integer::~Integer()
{
	std::cout << "Destructor is called: "<< _n << std::endl;
}

int Integer::getVal()const
{
	return this->_n;
}

Integer& Integer::operator=(Integer const & rhs)
{
	std::cout << "Assignation operator called from " << this->_n;
	std::cout << " to "<< rhs.getVal() << std::endl;
	this->_n = rhs.getVal();
	return *this;
}

Integer	Integer::operator+(Integer const & rhs) const
{
	std::cout << "Addition operator called with "<< this->_n;
	std::cout << " add "<< rhs.getVal() << std::endl;

	return Integer(this->_n + rhs.getVal());
}//operator + est diff des autres operators et renvoi que une copie et non pointeur

std::ostream & operator<<(std::ostream & o, Integer const & rhs)
{
	o << rhs.getVal();
	return o;
}
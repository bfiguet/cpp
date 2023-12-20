/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:55:23 by bfiguet           #+#    #+#             */
/*   Updated: 2023/12/20 14:16:41 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): _n(0)
{
	std::cout << "Default Constructor called"<< std::endl;
}

Fixed::Fixed(Fixed const & rhs)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = rhs;
}

Fixed & Fixed::operator=(Fixed const & rhs)
{
	if (this != &rhs)
	this->_n = rhs.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called"<< std::endl;
}

int	Fixed::getRawBits()const
{
	std::cout << "getRawBits member function called"<< std::endl;
	return this->_n;
}

void Fixed::setRawBits(int const raw)
{
	this->_n = raw;
}

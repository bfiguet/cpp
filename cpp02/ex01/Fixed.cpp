/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:55:23 by bfiguet           #+#    #+#             */
/*   Updated: 2023/12/20 15:58:12 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): _n(0)
{
	std::cout << "Default Constructor called"<< std::endl;
}

Fixed::Fixed(int const d): _n(d <<_bit)
{
	std::cout << "Int constructor called" << std::endl;
}
Fixed::Fixed(float const fl): _n(roundf(fl * (1 << _bit)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(Fixed const & rhs)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = rhs;
}

Fixed & Fixed::operator=(Fixed const & rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
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
	return this->_n;
}

void Fixed::setRawBits(int const raw)
{
	this->_n = raw;
}

std::ostream & operator<<(std::ostream & o, Fixed const & i)
{
	o << i.toFloat();
	return o;
}

float	Fixed::toFloat()const
{
	return (float)this->_n / (1 << _bit);
}

int		Fixed::toInt()const
{
	return _n >> _bit;
}

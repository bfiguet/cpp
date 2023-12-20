/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:55:23 by bfiguet           #+#    #+#             */
/*   Updated: 2023/12/20 16:49:58 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): _n(0) {}

Fixed::Fixed(int const d): _n(d <<_bit) {}
Fixed::Fixed(float const fl): _n(roundf(fl * (1 << _bit))) {}
Fixed::~Fixed() {}
Fixed::Fixed(Fixed const & rhs)
{
	*this = rhs;
}

Fixed & Fixed::operator=(Fixed const & rhs)
{
	if (this != &rhs)
		this->_n = rhs.getRawBits();
	return *this;
}

bool	Fixed::operator<(Fixed const & rhs) const
{
	return this->getRawBits() < rhs.getRawBits();
}

bool	Fixed::operator>(Fixed const & rhs) const
{
	return this->getRawBits() > rhs.getRawBits();
}

bool	Fixed::operator>=(Fixed const & rhs) const
{
	return this->getRawBits() >= rhs.getRawBits();
}
bool	Fixed::operator<=(Fixed const & rhs) const
{
	return this->getRawBits() <= rhs.getRawBits();
}
bool	Fixed::operator==(Fixed const & rhs) const
{
	return this->getRawBits() == rhs.getRawBits();
}
bool	Fixed::operator!=(Fixed const & rhs) const
{
	return this->getRawBits() != rhs.getRawBits();
}

Fixed	Fixed::operator+(Fixed const & rhs) const
{
	return (Fixed(this->toFloat() + rhs.toFloat()));
}
Fixed	Fixed::operator-(Fixed const & rhs) const
{
	return (Fixed(this->toFloat() - rhs.toFloat()));
}
Fixed	Fixed::operator*(Fixed const & rhs) const
{
	return (Fixed(this->toFloat() * rhs.toFloat()));
}
Fixed	Fixed::operator/(Fixed const & rhs) const
{
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

Fixed &	Fixed::operator++()
{
	++this->_n;
	return (*this);
}
Fixed 	Fixed::operator++(int)
{
	Fixed	tmp(*this);
	++(*this);
	return tmp;
}
Fixed &	Fixed::operator--()
{
	--this->_n;
	return (*this);
}
Fixed 	Fixed::operator--(int)
{
	Fixed	tmp(*this);
	--(*this);
	return tmp;
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

Fixed &	Fixed::min(Fixed & lhs, Fixed & rhs)
{
	if (lhs <= rhs)
		return (lhs);
	return rhs;
}
Fixed &	Fixed::max(Fixed & lhs, Fixed & rhs)
{
	if (lhs >= rhs)
		return (lhs);
	return rhs;
}
Fixed const &	Fixed::min(Fixed const & lhs, Fixed  const & rhs)
{
	if (lhs <= rhs)
		return (lhs);
	return rhs;
}
Fixed const &	Fixed::max(Fixed const & lhs, Fixed  const & rhs)
{
	if (lhs >= rhs)
		return (lhs);
	return rhs;
}

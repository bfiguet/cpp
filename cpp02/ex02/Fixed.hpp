/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:54:47 by bfiguet           #+#    #+#             */
/*   Updated: 2023/12/20 16:42:07 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>
//i = 0 
//lhs : left-hand side ->i
//rhs : right-hand side ->0

class Fixed
{
public:
	Fixed();
	Fixed(int const d);
	Fixed(float const fl);
	Fixed(Fixed const & rhs);
	~Fixed();

	bool	operator<(Fixed const & rhs) const;
	bool	operator>(Fixed const & rhs) const;
	bool	operator>=(Fixed const & rhs) const;
	bool	operator<=(Fixed const & rhs) const;
	bool	operator==(Fixed const & rhs) const;
	bool	operator!=(Fixed const & rhs) const;

	Fixed & operator=(Fixed const & rhs);
	Fixed	operator+(Fixed const & rhs) const;
	Fixed	operator-(Fixed const & rhs) const;
	Fixed	operator*(Fixed const & rhs) const;
	Fixed	operator/(Fixed const & rhs) const;

	Fixed &	operator++();
	Fixed 	operator++(int);
	Fixed &	operator--();
	Fixed 	operator--(int);

	int		getRawBits()const;
	void	setRawBits(int const raw);

	float	toFloat()const;
	int		toInt()const;

	static Fixed &	min(Fixed & lhs, Fixed & rhs);
	static Fixed &	max(Fixed & lhs, Fixed & rhs);
	static Fixed const &	min(Fixed const & lhs, Fixed  const & rhs);
	static Fixed const &	max(Fixed const & lhs, Fixed  const & rhs);

private:
	int _n;
	static const int _bit = 8;

};

std::ostream & operator<<(std::ostream & o, Fixed const & i);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:54:47 by bfiguet           #+#    #+#             */
/*   Updated: 2023/12/20 16:09:04 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
public:
	Fixed();
	Fixed(int const d);
	Fixed(float const fl);
	Fixed(Fixed const & rhs);
	Fixed & operator=(Fixed const & rhs);
	~Fixed();

	int		getRawBits()const;
	void	setRawBits(int const raw);

	float	toFloat()const;
	int		toInt()const;

private:
	int _n;
	static const int _bit = 8;

};

std::ostream & operator<<(std::ostream & o, Fixed const & i);

#endif
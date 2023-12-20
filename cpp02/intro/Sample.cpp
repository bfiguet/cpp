/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:02:30 by bfiguet           #+#    #+#             */
/*   Updated: 2023/12/19 11:40:34 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sample.hpp"

Sample::Sample(): _foo(0)
{
	std::cout << "Default Constructor called"<< std::endl;
}

Sample::Sample(int const n) : _foo(n)
{
	std::cout << "Parametric Constructor called"<< std::endl;
}

Sample::Sample(Sample const & src)
{
	std::cout << "Cppy Constructor called"<< std::endl;
}

Sample::~Sample()
{
	std::cout << "Destructor called"<< std::endl;
}

int Sample::getFoo()const
{
	return this->_foo;
}

Sample & Sample::operator=(Sample const & rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &rhs)
		this->_foo = rhs.getFoo();
	return *this;
}

void	Sample::bar(char const c)const
{
	std::cout << "Member founction bar called with char overload"<< c << std::endl;
}

void	Sample::bar(int const n)const
{
	std::cout << "Member founction bar called with int overload"<< n << std::endl;
}

void	Sample::bar(float const z)const
{
	std::cout << "Member founction bar called with float overload"<< z << std::endl;
}

void	Sample::bar(Sample const & i)const
{
	(void) i;
	std::cout << "Member founction bar called with Sample overload"<< std::endl;
}

std::ostream & operator<<(std::ostream & o, Sample const & i)
{
	o << "The value of _foo is " << i.getFoo();
	return o;
}

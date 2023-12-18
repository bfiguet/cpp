/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:02:30 by bfiguet           #+#    #+#             */
/*   Updated: 2023/12/18 13:13:14 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sample.hpp"

Sample::Sample()
{
	std::cout << "Constructor is called"<< std::endl;
}

Sample::~Sample()
{
	std::cout << "Destructor is called"<< std::endl;
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 12:39:14 by bfiguet           #+#    #+#             */
/*   Updated: 2023/12/14 13:27:18 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "Hello I'm a new zombie" << std::endl;
	return;
}

//Zombie::Zombie(std::string name) : _name(name)
//{
//	std::cout << "Hello I'm a zombie, my name is " << this->_name << std::endl;
//	return;
//}

void	Zombie::announce() const
{
	std::cout << this->_name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
	return;
}

void	Zombie::setName(std::string const name)
{
	this->_name = name;
	return;
}

Zombie::~Zombie()
{
	std::cout << this->_name << " is dead" << std::endl;
	return;
}

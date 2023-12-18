/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:17:08 by bfiguet           #+#    #+#             */
/*   Updated: 2023/12/14 12:01:57 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name): _name(name)
{
	std::cout << "Hello I'm a zombie, my name is " << this->_name << std::endl;
	return;
}

void	Zombie::announce() const
{
	std::cout << this->_name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
	return;
}

Zombie::~Zombie()
{
	std::cout << this->_name << " is dead" << std::endl;
	return;
}

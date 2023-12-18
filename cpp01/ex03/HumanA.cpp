/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:48:12 by bfiguet           #+#    #+#             */
/*   Updated: 2023/12/14 15:45:34 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string const name, Weapon const &weapon): _name(name), _weapon(weapon)
{
}

HumanA::~HumanA()
{
}

void	HumanA::attack()const
{
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}

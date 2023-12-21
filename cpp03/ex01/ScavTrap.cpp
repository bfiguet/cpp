/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 11:51:21 by bfiguet           #+#    #+#             */
/*   Updated: 2023/12/21 16:14:41 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap(){
	std::cout << "ScavTrap Default constructor " << this->_name << " called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(std:: string name): ClapTrap(name){
	std::cout << "ScavTrap default Constructor called for : " << this->_name << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}
ScavTrap::ScavTrap(const ScavTrap & rhs): ClapTrap(rhs){
	std::cout << "ScavTrap Copy Constructor Called" << std::endl;
	*this = rhs;
}

ScavTrap& ScavTrap::operator=(const ScavTrap & rhs){
	std::cout << "ScavTrap assignment operator called" << std::endl;
	this->_name = rhs._name;
	this->_hitPoints = rhs._hitPoints;
	this->_energyPoints = rhs._energyPoints;
	this->_attackDamage = rhs._attackDamage;
	return *this;
}
void	ScavTrap::attack(const std::string & target){
	if (this->_hitPoints > 0 && this->_energyPoints > 0)
	{
		std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!"<< std::endl;
		this->_energyPoints--;
	}
	else if (this->_energyPoints == 0)
		std::cout << "ScavTrap " << this->_name << " does not have enough Energy points to attack." << std::endl;
	else
		std::cout << "ScavTrap " << this->_name << " cannot attack because he is dead." << std::endl;
}
void	ScavTrap::guardGate(){
	std::cout << "ScavTrap: " << this->_name << " has entered Gate keeper mode" << std::endl;
}

ScavTrap::~ScavTrap(){
	std::cout << "ScavTrap Destructor called for : " << this->_name << std::endl;
}

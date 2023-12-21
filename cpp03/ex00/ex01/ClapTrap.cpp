/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 18:30:53 by bfiguet           #+#    #+#             */
/*   Updated: 2023/12/21 16:14:17 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("Serena"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap Default constructor " << _name << " called" << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap Default constructor " << _name << " called" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap& rhs ) {
	std::cout << "ClapTrap Copy Constructor Called" << std::endl;
	*this = rhs;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap Destructor " << _name << " called" << std::endl;
}

ClapTrap & ClapTrap::operator=(ClapTrap const & rhs) {
	_name = rhs._name;
	_hitPoints = rhs._hitPoints;
	_energyPoints = rhs._energyPoints;
	_attackDamage = rhs._attackDamage;
	return *this;
}

void	ClapTrap::attack(const std::string & target) {
	if (this->_hitPoints > 0 && this->_energyPoints > 0)
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints--;
	}
	else if (this->_energyPoints == 0)
		std::cout << "ClapTrap " << this->_name << " does not have enough Energy points to attack." << std::endl;
	else
		std::cout << "ClapTrap " << this->_name << " cannot attack because he is dead." << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hitPoints > 0)
	{
		if (this->_hitPoints > amount)
		{
			this->_hitPoints -= amount;
			std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage!"<< std::endl;
		}
		else
		{
			this->_hitPoints = 0;
			std::cout << "ClapTrap " << this->_name << " is dead!" << std::endl;
		}
	}
	else
		std::cout << "ClapTrap " << this->_name << " cannot take damage because he is already dead." << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->_hitPoints > 0 && this->_energyPoints > 0 && this->_hitPoints + amount <= 10)
	{
		std::cout << "ClapTrap " << this->_name << " has been repaired and gained " << amount << " Hit Points!"<< std::endl;
		this->_energyPoints--;
		this->_hitPoints += amount;
	}
	else if (this->_hitPoints + amount > 10)
		std::cout << "ClapTrap " << this->_name << " cannot heal to have more than 10 Hit Points." << std::endl;
	else if (this->_energyPoints == 0)
		std::cout << "ClapTrap " << this->_name << " does not have enough Energy Points to be repaired." << std::endl;
	else
		std::cout << "ClapTrap " << this->_name << " cannot be repaired because he is dead." << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 18:30:53 by bfiguet           #+#    #+#             */
/*   Updated: 2023/12/20 20:39:28 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("Player"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "Default constructor " << this->_name << " called" << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "Default constructor " << name << " called" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap& rhs ) {
	std::cout << "Copy Constructor Called" << std::endl;
	*this = rhs;
}

ClapTrap::~ClapTrap() {
	std::cout << "Destructor " << this->_name << " called" << std::endl;
}

ClapTrap & ClapTrap::operator=(ClapTrap const & rhs) {
	_name = rhs._name;
	_hitPoints = rhs._hitPoints;
	_energyPoints = rhs._energyPoints;
	_attackDamage = rhs._attackDamage;
	return *this;
}

void	ClapTrap::attack(const std::string & target) {
	std::cout << this->_name << " attacks " << target <<" and hits for " << this->_attackDamage << " damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	std::cout << this->_name << " is dealt " << amount << " damage(s)!" << std::endl;
	if (this->_hitPoints <= amount){
		this->_hitPoints = 0;
		std::cout << this->_name << " can't take anymore damage: Hit points = 0." << std::endl;
	}
	else
		this->_hitPoints -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	std::cout << this->_name << " is being repaired for " << amount << " Hit points !Cool !" << std::endl;
	this->_hitPoints += amount;
}

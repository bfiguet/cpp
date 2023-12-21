/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 11:54:38 by bfiguet           #+#    #+#             */
/*   Updated: 2023/12/21 18:01:46 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap (): ClapTrap(){
	std::cout << "FragTrap Default constructor " << this->_name << " called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap (std::string name): ClapTrap(name){
	std::cout << "FragTrap default Constructor called for : " << this->_name << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(FragTrap const & rhs): ClapTrap(rhs){
	std::cout << "FragTrap Copy Constructor Called" << std::endl;
	*this = rhs;
}

FragTrap::~FragTrap(){
	std::cout << "FragTrap Destructor called for : " << this->_name << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap & rhs){
	std::cout << "FragTrap assignment operator called" << std::endl;
	this->_name = rhs._name;
	this->_hitPoints = rhs._hitPoints;
	this->_energyPoints = rhs._energyPoints;
	this->_attackDamage = rhs._attackDamage;
	return *this;
}

void	FragTrap::attack(const std::string & target){
	std::cout << "FragTrap " << _name << " attacks " << target << " dealing " << this->_attackDamage << " damage(s)!" << std::endl;
}

void	FragTrap::highFivesGuys(){
	std::cout << "Give me a High Five !" << std::endl;
}

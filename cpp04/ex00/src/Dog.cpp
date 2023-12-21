/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 18:31:33 by bfiguet           #+#    #+#             */
/*   Updated: 2023/12/21 18:35:29 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): Animal(){
	this->_type = "Dog";
	std::cout << _type << " default constructor called" << std::endl;
}

Dog::Dog(Dog const & rhs): Animal(rhs){
	std::cout << _type << " copy constructor called" << std::endl;
	*this = rhs;
}

Dog::~Dog(){
	std::cout << _type << " destructor called" << std::endl;
}

Dog & Dog::operator=(const Dog & rhs){
	std::cout << this->_type << " assignment operator called" << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return *this;
}

void	Dog::makeSound()const{
	std::cout << this->_type << ": Ouaf Ouaf" << std::endl;
}

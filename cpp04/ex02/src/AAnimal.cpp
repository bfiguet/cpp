/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 12:00:47 by bfiguet           #+#    #+#             */
/*   Updated: 2023/12/22 01:04:48 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(): _type("AAnimal"){
	std::cout << _type << " default constructor called" << std::endl;
}

AAnimal::AAnimal(AAnimal const & rhs){
	std::cout << _type << " copy constructor called" << std::endl;
	*this = rhs;
}
AAnimal::~AAnimal(){
	std::cout << _type << " destructor called" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal & rhs){
	std::cout << "AAnimal assignment operator called" << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return *this;
}

std::string	const & AAnimal::getType()const{
	return this->_type;
}

void	AAnimal::makeSound()const{
	std::cout << this->_type <<" : Unidentifiable sound, sorry" << std::endl;
}

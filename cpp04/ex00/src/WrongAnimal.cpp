/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 18:42:07 by bfiguet           #+#    #+#             */
/*   Updated: 2023/12/21 18:48:45 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): _type("Unknown"){
	std::cout << "Animal " << _type << " default constructor called" << std::endl;
}
WrongAnimal::WrongAnimal(std::string const & type): _type(type){
	std::cout << "Animal " << _type << " type constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const & rhs){
	std::cout << "Animal " << _type << " copy constructor called" << std::endl;
	*this = rhs;
}

WrongAnimal::~WrongAnimal(){
	std::cout << "Animal " << _type << " destructor called" << std::endl;
}

WrongAnimal & WrongAnimal::operator=(WrongAnimal const & rhs){
	std::cout << this->_type << " assignment operator called" << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return *this;
}

std::string const & WrongAnimal::getType()const{
	return this->_type;
}
void	WrongAnimal::makeSound()const{
	std::cout << this->_type <<" : we don't know, sorry" << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 12:00:47 by bfiguet           #+#    #+#             */
/*   Updated: 2023/12/21 19:05:28 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(): _type("Animal"){
	std::cout << "Animal " << _type << " default constructor called" << std::endl;
}
Animal::Animal(std::string const & type): _type(type){
	std::cout << "Animal " << _type << " type constructor called" << std::endl;
}
Animal::Animal(Animal const & rhs){
	std::cout << "Animal " << _type << " copy constructor called" << std::endl;
	*this = rhs;
}
Animal::~Animal(){
	std::cout << "Animal " << _type << " destructor called" << std::endl;
}

Animal& Animal::operator=(const Animal & rhs){
	std::cout << "Animal assignment operator called" << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return *this;
}

std::string	const & Animal::getType()const{
	return this->_type;
}
void	Animal::makeSound()const{
	std::cout << this->_type <<" : Unidentifiable screech, sorry" << std::endl;
}

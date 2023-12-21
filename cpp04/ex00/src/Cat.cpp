/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 18:23:02 by bfiguet           #+#    #+#             */
/*   Updated: 2023/12/21 18:34:07 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): Animal(){
	this->_type = "Cat";
	std::cout << _type << " default constructor called" << std::endl;
}
Cat::Cat(Cat const & rhs): Animal(rhs){
	std::cout << _type << " copy constructor called" << std::endl;
	*this = rhs;
}

Cat::~Cat(){
	std::cout << _type << " destructor called" << std::endl;
}

Cat & Cat::operator=(const Cat  & rhs){
	std::cout << this->_type << " assignment operator called" << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return *this;
}
void	Cat::makeSound()const{
	std::cout << this->_type << ": Miaou" << std::endl;
}

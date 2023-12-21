/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 18:51:48 by bfiguet           #+#    #+#             */
/*   Updated: 2023/12/21 18:56:51 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal(){
	this->_type = "WrongCat";
	std::cout << _type << " default constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const & rhs): WrongAnilam(rhs){
	std::cout << _type << " copy constructor called" << std::endl;
	*this = rhs;
}

WrongCat::~WrongCat(){
	std::cout << _type << " destructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat & rhs){
	std::cout << this->_type << " assignment operator called" << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return *this;
}

void	WrongCat::makeSound()const{
	std::cout << this->_type << ": Miaouuuuu" << std::endl;
}

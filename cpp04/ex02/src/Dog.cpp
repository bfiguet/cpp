/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 18:31:33 by bfiguet           #+#    #+#             */
/*   Updated: 2023/12/22 00:55:23 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): AAnimal(), _brain(new Brain){
	this->_type = "Dog";
	std::cout << _type << " default constructor called" << std::endl;
}

Dog::Dog(Dog const & rhs): AAnimal(rhs), _brain(NULL){
	std::cout << _type << " copy constructor called" << std::endl;
	*this = rhs;
}

Dog::~Dog(){
	std::cout << _type << " destructor called" << std::endl;
	delete this->_brain;
}

Dog & Dog::operator=(const Dog & rhs){
	std::cout << this->_type << " assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->_type = rhs._type;
		if (this->_brain != NULL)
			delete this->_brain;
		this->_brain = new Brain(*rhs._brain);
	}
	return *this;
}

void	Dog::makeSound()const{
	std::cout << this->_type << ": Ouaf Ouaf" << std::endl;
}

void	Dog::setIdea(int i, std::string idea) const{
	if (i < 100)
		_brain->setIdea(i, idea);
}

void	Dog::showIdea()const
{
	for(int i = 0; i < 100; i++)
	{
		if (!_brain->getIdea(i).empty())
			std::cout << _brain->getIdea(i) << std::endl;
	}
}

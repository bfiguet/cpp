/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 18:23:02 by bfiguet           #+#    #+#             */
/*   Updated: 2023/12/22 00:54:59 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): AAnimal(), _brain(new Brain()){
	this->_type = "Cat";
	std::cout << _type << " default constructor called" << std::endl;
}
Cat::Cat(Cat const & rhs): AAnimal(rhs), _brain(NULL){
	std::cout << _type << " copy constructor called" << std::endl;
	*this = rhs;
}

Cat::~Cat(){
	std::cout << _type << " destructor called" << std::endl;
	delete this->_brain;
}

Cat & Cat::operator=(const Cat  & rhs){
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
void	Cat::makeSound()const{
	std::cout << this->_type << ": Miaou" << std::endl;
}

void	Cat::setIdea(int i, std::string idea) const{
	if (i < 100)
		_brain->setIdea(i, idea);
}

void	Cat::showIdea()const
{
	for(int i = 0; i < 100; i++)
	{
		if (!_brain->getIdea(i).empty())
			std::cout << _brain->getIdea(i) << std::endl;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 12:15:49 by bfiguet           #+#    #+#             */
/*   Updated: 2023/12/21 23:59:59 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(){
	std::cout << "Brain default constructor called." << std::endl;
}

Brain::Brain(Brain const & rhs){
	std::cout << "Brain copy constructor called." << std::endl;
	*this = rhs;
}

Brain::~Brain(){
	std::cout << "Brain destructor called." << std::endl;
}

Brain & Brain::operator=(const Brain  & rhs){
	std::cout << "Brain assignment operator called." << std::endl;
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = rhs._ideas[i];
	return (*this);
}

std::string const Brain::getIdea(int i)const{
	if (i < 0)
		i= 0;
	if (i < 100)
		return this->_ideas[i];
	else
		return "too many ideas.";
}

void	Brain::setIdea(int i, std::string const idea){
	if (i < 0)
		return ;
	if ( i < 100)
		this->_ideas[i] = idea;
	else
		std::cout <<"No idea?" << std::endl;
}

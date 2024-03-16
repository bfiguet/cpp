/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:43:03 by bfiguet           #+#    #+#             */
/*   Updated: 2024/03/16 19:23:54 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(){
	std::cout << "Constructor Intern called" << std::endl;
}

Intern::Intern(const Intern &src){ 
	*this = src;
	std::cout << "Constructor copy of Intern called" << std::endl;
}

Intern::~Intern(){
	std::cout << "Destructor Intern called." << std::endl;
}

Intern	&Intern::operator=(const Intern &src){
	(void)src;
	return *this;
}

static AForm*	Shru(std::string target){
	return new ShrubberyCreationForm(target);
}

static AForm*	Robot(std::string target){
	return new RobotomyRequestForm(target);
}

static AForm*	President(std::string target){
	return new PresidentialPardonForm(target);
}

AForm	*Intern::makeForm(std::string name, std::string target){
	std::string tab[] ={"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm*	(*makeFunc[])(std::string target) = {&Shru, &Robot, &President};
	for (int i = 0; i < 3; i++){
		if (name == tab[i]) {
			std::cout <<"Intern creates " << name << std::endl;
			return makeFunc[i](target);
		}	
	}
	std::cout << "Intern can't creates " << name << std::endl;
	return NULL;
}

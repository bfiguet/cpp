/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:01:35 by bfiguet           #+#    #+#             */
/*   Updated: 2024/03/16 14:10:55 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("Default Shrubbery Creation", 145, 137){
	_target = "Default";
	std::cout << "Constructor Default Shrubbery Creation Form called." << std::endl;
};

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& cpy): AForm(cpy.getName(), cpy.getSignGrade(), cpy.getExecGrade()){
	_target = cpy.getTarget();
	std::cout << "Constructor a copy of Shrubbery Creation Form called for " << _target << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target): AForm("Shrubbery Creation", 145, 137){
	_target = target;
	std::cout << "Constructor Shrubbery Creation Form called for " << _target << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
	std::cout << "Destructor Shrubbery Creation Form called for " << _target << std::endl;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src){
	std::cout << "Shrubbery Creation Form for " << _target << "'s assignment operator called." << std::endl;
	if (this != &src)
		this->_target = src.getTarget();
	return *this;
}

std::string	ShrubberyCreationForm::getTarget()const{return _target;}

void		ShrubberyCreationForm::execute(const Bureaucrat& executor)const{
	std::string		file = _target + "_shrubbery";
	std::ofstream	o(file.c_str());
	if (getStatus() == false)
		throw UnsignedException();
	if (executor.getGrade() > getExecGrade())
		throw GradeTooLowException();
	else
	{
		std::string tree = 
		"  ,%&%&%,		 <3k	\n"
		" ,%\\&%//%,		 \\//	\n"
		",&%&%&%&%&%&,	@@@@@@	\n"
		",%&%&//&\\%&,   @@@@@@@@	\n"
		" ,%&\\%&//%,	   @@@@@@@@	\n"
		" ,&%&|#|%&%, 	@@@@@@	\n"
		"     |#|		  ||	\n"
		"__\\/_|#|_\\_//__\\/ ||_\\/\n";
		if (o.is_open())
			o << tree;
		else
			std::cout << "Error, " << file << "isn't open." << std::endl;
	}
}

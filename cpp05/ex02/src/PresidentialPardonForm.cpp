/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:40:46 by bfiguet           #+#    #+#             */
/*   Updated: 2024/03/13 17:58:15 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("Default Presidential Pardon Form", 25, 5){
	_target = "Default";
	std::cout << "Constructor Default Presidential PArdon Form called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target): AForm("Presidential Pardon Form", 25, 5){
	_target = target;
	std::cout << "Constructor Presidential Pardon Form called for "<< _target << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& cpy): AForm(cpy.getName(), cpy.getSignGrade(), cpy.getExecGrade()){
	_target = cpy.getTarget();
	std::cout << "Constructor a copy of Presidential Pardon Form called for "<< _target << std::endl;
}

~PresidentialPardonForm::PresidentialPardonForm(){
	std::cout << "Destructor Presidential Pardon Form called for " << _target << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& src){
	std::cout << "Presidential Pardon Form for " << _target << "'s assignment operator called." << std::endl;
	if (this != &src)
		_target = src.getTarget();
	return *this;
}

std::string	PresidentialPardonForm::getTarget()const{return _target;}

void	PresidentialPardonForm::execute(const Bureaucrat& executor)const{
	if (_getStatus())
		throw AForm::UnsignedException();
	if (executor.getGrade() > getGradeExec())
		throw AForm::GradeToolowException();
	else
		std::cout << executor.getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

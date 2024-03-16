/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:10:05 by bfiguet           #+#    #+#             */
/*   Updated: 2024/03/16 13:43:52 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("Default Robotory Request", 72, 45){
	_target = "Default";
	std::cout << "Constructor Default Robotory Form called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target): AForm("Robotory request", 72, 45){
	_target = target;
	std::cout << "Constructor Robotory Request Form called for " << _target << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& cpy): AForm(cpy.getName(), cpy.getSignGrade(), cpy.getExecGrade()){
	_target = cpy.getTarget();
	std::cout << "Constructor a copy of Robotory Request Form called for " << _target << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(){
	std::cout << "Destructor Robotory Request Form called for " << _target << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& src){
	std::cout << "Robotory request Form for " << _target << "'s assignment operator called." << std::endl;
	if (this != &src)
		_target = src.getTarget();
	return *this;
}

std::string	RobotomyRequestForm::getTarget()const{ return _target;}

void	RobotomyRequestForm::execute(const Bureaucrat& executor)const{
	if (getStatus())
		throw UnsignedException();
	if (executor.getGrade() > getExecGrade())
		throw GradeTooLowException();
	else
	{
		static int	i;
		std::cout << "Drilling noises" << std::endl;
		if (i % 2 == 0)
			std::cout << _target << " has been robotomized." << std::endl;
		else
			std::cout << _target << ", the robotomy failed." << std::endl;
		std::cout << std::endl;
		i++;
	}
}

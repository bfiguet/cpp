/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 09:48:46 by bfiguet           #+#    #+#             */
/*   Updated: 2024/02/15 12:31:21 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
//COPIER COLLER EXO 00 TOUT VERIFIER!!!!
Bureaucrat::Bureaucrat() : _name("Default"), _grade(150){
	try {
		this->setGrade(150);
	} catch (std::exception &e) {
		std::cout << "Bureaucrat Default Constructor called" << std::endl;	}
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name){
	try
	{
		this->setGrade(grade);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "Bureaucrat Constructor called for " << _name << std::endl;
	
}

Bureaucrat::~Bureaucrat(){ std::cout << "Bureaucrat Destructor called for " << _name << std::endl;}

std::string const	Bureaucrat::getName()const{return _name;}

int	Bureaucrat::getGrade()const{ return _grade;}

void	Bureaucrat::setGrade(int grade){
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade = grade;
}

const char*	Bureaucrat::GradeTooLowException::what() const throw(){
	return "Grade is too low.";
}

const char*	Bureaucrat::GradeTooHighException::what() const throw(){
	return "Grade is too high.";
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat &src){
	std::cout << "Bureaucrat Assignment operator called for Bureaucrat." << std::endl;
	if (this != &src){
		_grade = src.getGrade();
	}
	return *this;
}

void	Bureaucrat::increment(){
	if(_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void	Bureaucrat::decrement(){
	if(_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

std::ostream	&operator<<(std::ostream &o, const Bureaucrat &curr){
	o << cur.getName() << ", bureaucrat grade " << cur.getGrade() << "." << std::endl;
	return o;
}

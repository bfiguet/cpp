/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 09:48:46 by bfiguet           #+#    #+#             */
/*   Updated: 2024/03/13 19:17:40 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150){
	std::cout << "Bureaucrat Default Constructor called with grade 150." << std::endl;
}

Bureaucrat::Bureaucrat(int grade): _name("Default"){
	try{
		this->setGrade(grade);
	}catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	std::cout << "Bureaucrat Default Constructor called for grade." << grade << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name){
	try {
		this->setGrade(grade);
	}catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	std::cout << "Bureaucrat " << this->_name << " has grade " << this->_grade << "." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src): _name(src.getName() + "_new"){
	(*this) = src;
	std::cout << "Bureaucrat copy Constructor called for " << _name << " with grade " << _grade << "." << std::endl;
}

Bureaucrat::~Bureaucrat(){ 
	std::cout << "Bureaucrat Destructor called for " << _name << "." << std::endl;
}

void	Bureaucrat::setGrade(int grade){
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade = grade;
}

std::string const	Bureaucrat::getName()const{return _name;}

int	Bureaucrat::getGrade()const{ return _grade;}

void	Bureaucrat::increment(){
	if(_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
	std::cout << "Bureaucrat " << _name << "'s grade has been increment by 1 and now has grade is " << _grade << "." << std::endl;
}

void	Bureaucrat::decrement(){
	if(_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
	std::cout << "Bureaucrat " << _name << "'s grade has been decrement by 1 and now has grade is " << _grade << "." << std::endl;
}

const char*	Bureaucrat::GradeTooLowException::what() const throw(){return "Grade is too low.\n";}

const char*	Bureaucrat::GradeTooHighException::what() const throw(){return "Grade is too high.\n";}

void	Bureaucrat::signForm(const AForm& form)const {
	if (form.getStatus())
		std::cout << "Bureaucrat " << _name << " could not sign Form " << form.getName() << "." << std::endl;
	else
		std::cout << "Bureaucrat " << _name << " signed Form " << form.getName() << "." << std::endl;
}

void	Bureaucrat::executeAForm(AForm const & form){
	if (form.getStatus() == false)
		throw AForm::UnsignedException();
	if (getGrade() > form.getExecGrade())
		throw AForm::GradeTooLowException();
	else
		std::cout << "Bureaucrat " << _name << " has executed form " << form.getName() << "." << std::endl;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat &src){
	std::cout << "Bureaucrat Assignment operator called for Bureaucrat." << std::endl;
	if (this != &src){
		_grade = src.getGrade();
	}
	return *this;
}

std::ostream&	operator<<(std::ostream& o, const Bureaucrat& curr){
	o << curr.getName() << ", bureaucrat grade " << curr.getGrade() << "." << std::endl;
	return o;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:30:41 by bfiguet           #+#    #+#             */
/*   Updated: 2024/03/13 19:00:40 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(): _name("Default"), _signGrade(150), _execGrade(150), _isSign(false){
	std::cout << "Constructor AForm " << _name << " called" << std::endl;
}

AForm::AForm(std::string const name, int const signGrade, int const execGrade): _name(name), _signGrade(signGrade), _execGrade(execGrade), _isSign(false){
	if (_signGrade > 150 || _execGrade > 150)
		throw AForm::GradeTooLowException();
	else if (_signGrade < 1 || _execGrade < 1)
		throw AForm::GradeTooHighException();
	else {
		std::cout << "Constructor AForm " << _name << " called with grade to sign " 
			<< _signGrade << " and grade to execute " << _execGrade << std::endl;
	}
}

AForm::AForm(const AForm &src): _name(src.getName() + "_copy"), _signGrade(src.getSignGrade()), _execGrade(src.getExecGrade()), _isSign(src.getStatus()){
	std::cout << "Constructor copy of AForm " << _name << " called" << std::endl;
}

AForm::~AForm(){
	std::cout << "Destructor AForm " << _name << " called." << std::endl;
}

std::string const	AForm::getName()const{ return _name;}

bool	AForm::getStatus()const{ return _isSign;}

int		AForm::getSignGrade()const{ return _signGrade;}

int		AForm::getExecGrade()const{return _execGrade;}

void	AForm::beSigned(const Bureaucrat& sign){
	if (_isSign == true)
		std::cout << "AForm " << _name << " has already been signed." << std::endl;
	if (sign.getGrade() <=  getSignGrade())
		return setStatus(true);	
	throw AForm::GradeTooLowException();
}

void	AForm::setStatus(bool const stat){ 
	_isSign = stat;
	std::cout << "AForm " << _name << "'s signed status has been set to " << _isSign << "." << std::endl;
}

const char*	AForm::Exception::what() const throw(){return "Default AForm Exception.\n";}

const char*	AForm::GradeTooLowException::what() const throw(){return "Grade is too low.\n";}

const char*	AForm::GradeTooHighException::what() const throw(){return "Grade is too high.\n";}

const char*	AForm::UnsignedException::what() const throw(){return "Form isn't signed.\n";}

AForm	&AForm::operator=(const AForm& src)
{
	std::cout << "AForm " << _name << "'s assignment operator called." << std::endl;
	if (this != &src)
		this->_isSign = src.getStatus();
	return (*this);
}

std::ostream&	operator<<( std::ostream& o, const AForm& curr ){
	o << "AForm " << curr.getName() << ", grade to sign is " 
		<< curr.getSignGrade() << " and grade to execute is " << curr.getExecGrade() << "." << std::endl;;
	if (curr.getStatus())
		o << "The AForm isn't signed." << std::endl;
	else
		o << "The AForm is signed." << std::endl;
	return o;
}

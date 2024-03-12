/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:30:41 by bfiguet           #+#    #+#             */
/*   Updated: 2024/03/12 12:44:26 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): _name("Default"), _signGrade(150), _execGrade(150), _isSign(false){
	std::cout << "Constructor Form " << _name << " called" << std::endl;
}

Form::Form(std::string const name, int const signGrade, int const execGrade): _name(name), _signGrade(signGrade), _execGrade(execGrade), _isSign(false){
	if (_signGrade > 150 || _execGrade > 150)
		throw Form::GradeTooLowException();
	else if (_signGrade < 1 || _execGrade < 1)
		throw Form::GradeTooHighException();
	else {
		std::cout << "Constructor Form " << _name << " called with grade to sign " 
			<< _signGrade << " and grade to execute " << _execGrade << std::endl;
	}
}

Form::Form(const Form &src): _name(src.getName() + "_copy"), _signGrade(src.getSignGrade()), _execGrade(src.getExecGrade()), _isSign(src.getStatus()){
	std::cout << "Constructor copy of Form " << _name << " called" << std::endl;
}

Form::~Form(){
	std::cout << "Destructor Form " << _name << " called." << std::endl;
}

std::string const	Form::getName()const{ return _name;}

bool	Form::getStatus()const{ return _isSign;}

int		Form::getSignGrade()const{ return _signGrade;}

int		Form::getExecGrade()const{return _execGrade;}

void	Form::beSigned(const Bureaucrat& sign){
	if (_isSign == true)
		throw Form::signException();
	if (sign.getGrade() <=  getSignGrade())
		return setStatus(true);	
	throw Form::GradeTooLowException();
}

void	Form::setStatus(bool const stat){ 
	_isSign = stat;
	std::cout << "Form " << _name << "'s signed status has been set to " << _isSign << "." << std::endl;
}

const char*	Form::signException::what() const throw(){return "The Form has already been signed\n";}

const char*	Form::GradeTooLowException::what() const throw(){return "Grade is too low\n";}

const char*	Form::GradeTooHighException::what() const throw(){return "Grade is too high\n";}

Form	&Form::operator=(const Form& src)
{
	std::cout << "Form " << _name << "'s assignment operator called." << std::endl;
	if (this != &src)
		this->_isSign = src.getStatus();
	return (*this);
}

std::ostream&	operator<<( std::ostream& o, const Form& curr ){
	o << "Form " << curr.getName() << ", grade to sign is " 
		<< curr.getSignGrade() << " and grade to execute is " << curr.getExecGrade() << "." << std::endl;;
	if (curr.getStatus())
		o << "The Form isn't signed." << std::endl;
	else
		o << "The Form is signed." << std::endl;
	return o;
}

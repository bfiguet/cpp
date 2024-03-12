/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:16:22 by bfiguet           #+#    #+#             */
/*   Updated: 2024/03/12 12:44:20 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;
class Form
{
private:
	std::string const	_name;
	int const			_signGrade;
	int const			_execGrade;
	bool				_isSign;
public:
	Form();
	Form(const std::string name, const int signGrade, const int execGrade);
	Form(const Form& src);
	~Form();

	Form&	operator=(const Form& src);

	std::string	const	getName()const;
	bool				getStatus()const;
	int					getSignGrade()const;
	int					getExecGrade()const;

	void				beSigned(const Bureaucrat& sign);
	void				setStatus(bool const stat);
	
	class signException : public std::exception {
		public:
			const char* what() const throw();
	};

	class GradeTooHighException : public Form::signException {
		public:
			const char* what() const throw();
	};

	class GradeTooLowException : public Form::signException {
		public:
			const char* what() const throw();
	};
};

std::ostream&	operator<<( std::ostream& o, const Form& curr );


#endif
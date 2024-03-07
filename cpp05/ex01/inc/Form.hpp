/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:16:22 by bfiguet           #+#    #+#             */
/*   Updated: 2024/02/29 11:53:01 by bfiguet          ###   ########.fr       */
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
	Form(std::string name, int signGrade, int execGrade);
	Form(const Form& src);
	~Form();

	Form&	operator=(const Form& src);

	std::string	const	getName()const;
	bool				getStatus()const;
	int					getSignGrade()const;
	int					getExecGrade()const;

	void				beSigned(const Bureaucrat& sign);
	void				setSatus(bool const stat);
	
	class signException {
		public:
			virtual const char* what() const throw();
	};
	
	class GradeTooHighException {
		public:
			virtual const char* what() const throw();
	};

	class GradeTooLowException {
		public:
			virtual const char* what() const throw();
	};
};

std::ostream&	operator<<( std::ostream& o, const Form& curr );


#endif
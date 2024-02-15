/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:16:22 by bfiguet           #+#    #+#             */
/*   Updated: 2024/02/15 12:30:28 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

class Bureaucrat;
class Form
{
private:
	std::string const	_name;
	bool				_isSign;
	int const			_reqGrade;
	int const			_execGrade;
public:
	Form();
	Form(std::string name, int _reqGrade, bool _isSign);
	Form(const Form &src);
	~Form();

	std::string const	getName()const;
	bool				getStatus()const;
	int					getreqGrade()const;
	int					getexecGrade()const;

	void				beSign(const Bureaucrat &sign);
	void				setSatus(bool stat);
	
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
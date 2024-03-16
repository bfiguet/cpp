/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:13:33 by bfiguet           #+#    #+#             */
/*   Updated: 2024/03/16 13:17:30 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

# include <fstream>
# include "Bureaucrat.hpp"

class Bureaucrat;
class AForm
{
private:
	std::string const	_name;
	int const			_signGrade;
	int const			_execGrade;
	bool				_isSign;

public:
	AForm();
	AForm(const std::string name, const int signGrade, const int execGrade);
	AForm(const AForm& src);
	virtual ~AForm();

	AForm&	operator=(const AForm& src);

	std::string	const	getName()const;
	bool				getStatus()const;
	int					getSignGrade()const;
	int					getExecGrade()const;

	void				beSigned(const Bureaucrat& sign);
	void				setStatus(bool const stat);
	virtual void		execute(Bureaucrat const &executor) const = 0;
	
	class AlreadySignException : public std::exception {
		public:
			virtual const char* what() const throw();
	};

	class GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const throw();
	};

	class UnsignedException : public std::exception {
		public:
			virtual const char* what() const throw();
	};
};

std::ostream&	operator<<( std::ostream& o, const AForm& curr);

#endif
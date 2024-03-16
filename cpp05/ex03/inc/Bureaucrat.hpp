/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 09:48:53 by bfiguet           #+#    #+#             */
/*   Updated: 2024/03/16 13:17:15 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>
# include "AForm.hpp"

class AForm;
class Bureaucrat
{

private:
	std::string	const		_name;
	int						_grade;

public:
	Bureaucrat();
	Bureaucrat( int grade);
	Bureaucrat(const std::string name, const int grade);
	Bureaucrat(const Bureaucrat &src);
	~Bureaucrat();

	Bureaucrat&				operator=(const Bureaucrat &src);
	
	std::string	const		getName()const;
	int						getGrade()const;

	void					setGrade(int grade);

	void					increment();
	void					decrement();
	void					signForm(AForm& form);
	void					executeAForm(const AForm& form) const;

	class GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const throw();
	};
	
};

std::ostream&	operator<<(std::ostream& o, Bureaucrat const &curr);

#endif
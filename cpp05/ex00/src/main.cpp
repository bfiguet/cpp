/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 09:47:55 by bfiguet           #+#    #+#             */
/*   Updated: 2024/02/24 12:37:54 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	{
		Bureaucrat *a = new Bureaucrat();
		std::cout << std::endl;
		try{
			a->increment();
		}catch(Bureaucrat::GradeTooHighException &e){
			std::cerr << e.what() << std::endl;
		}
		try{
			a->decrement();
		}catch(Bureaucrat::GradeTooLowException &e){
			std::cerr << e.what() << std::endl;
		}
		try{
			a->decrement();
		}catch(Bureaucrat::GradeTooLowException &e){
			std::cerr << e.what() << std::endl;
		}
		delete a;
		std::cout << std::endl;
	}
	std::cout << "-------------------------------------------------------" << std::endl;
	{
		Bureaucrat *a = new Bureaucrat(1);
		try{
			a->decrement();
		}catch(Bureaucrat::GradeTooLowException &e){
			std::cerr << e.what() << std::endl;
		}
		try{
			a->increment();
		}catch(Bureaucrat::GradeTooHighException &e){
			std::cerr << e.what() << std::endl;
		}
		try{
			a->increment();
		}catch(Bureaucrat::GradeTooHighException &e){
			std::cerr << e.what() << std::endl;
		}
		delete a;
		std::cout << std::endl;
	}
	std::cout << "-------------------------------------------------------" << std::endl;
	{
		Bureaucrat *a = NULL;
		try{
			a = new Bureaucrat(0);
		}catch(Bureaucrat::GradeTooHighException &e){
			std::cerr << e.what() << std::endl;
		}
		if (a != NULL)
			delete a;
	}
	std::cout << "-------------------------------------------------------" << std::endl;
	{
		Bureaucrat *a = NULL;
		try{
			a = new Bureaucrat(160);
		}catch(Bureaucrat::GradeTooLowException &e){
			std::cerr << e.what() << std::endl;
		}
		if (a != NULL)
			delete a;
		std::cout << std::endl;
	}
	std::cout << "-------------------------------------------------------" << std::endl;
	{
		Bureaucrat *a = new Bureaucrat("Peter", 120);
		a->decrement();

		Bureaucrat *b = new Bureaucrat(*a);
		delete a;
		
		b->decrement();
		delete b;
	}
	return 0;
}

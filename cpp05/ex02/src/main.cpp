/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:58:38 by bfiguet           #+#    #+#             */
/*   Updated: 2024/03/16 16:06:24 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	ShrubberyCreationForm shrubbery("Shrubbery");
	RobotomyRequestForm robotomy("Robotomy");
	PresidentialPardonForm presidential("Presidential");
	Bureaucrat Jam("Jam", 2);
	std::cout << "-------------------------------------------------------" << std::endl;
	try
	{
		Jam.executeAForm(shrubbery);
		std::cout << std::endl;
		Jam.executeAForm(robotomy);
		std::cout << std::endl;
		Jam.executeAForm(presidential);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "-------------------------------------------------------" << std::endl;
	try
	{
		shrubbery.beSigned(Jam);
		std::cout << std::endl;
		robotomy.beSigned(Jam);
		std::cout << std::endl;
		presidential.beSigned(Jam);
		std::cout << std::endl;
		Jam.executeAForm(shrubbery);
		std::cout << std::endl;
		Jam.executeAForm(robotomy);
		std::cout << std::endl;
		Jam.executeAForm(presidential);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}	
	std::cout << "-------------------------------------------------------" << std::endl;
	try
	{
		shrubbery.beSigned(Jam);
		std::cout << std::endl;
		Jam.executeAForm(shrubbery);
		std::cout << std::endl;
		Jam.executeAForm(robotomy);
		std::cout << std::endl;
		Jam.executeAForm(presidential);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}

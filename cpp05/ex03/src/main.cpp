/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:58:38 by bfiguet           #+#    #+#             */
/*   Updated: 2024/03/16 19:25:41 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main()
{
//	Bureaucrat *sam = new Bureaucrat("Sam", 1);
//	Intern *intern = new Intern();
//	AForm *robot = intern->makeForm("RobotomyRequestForm", "Robot");
//	AForm *shu = intern->makeForm("ShrubberyCreationForm", "Shu");
//	AForm *pres = intern->makeForm("PresidentialPardonForm", "President");
//	std::cout << std::endl;

//	robot->beSigned(*sam);
//	sam->signForm(*shu);
//	pres->beSigned(*sam);

//	std::cout << std::endl;

//	robot->execute(*sam);
//	sam->executeAForm(*shu);
//	sam->executeAForm(*pres);
//	std::cout << std::endl;

//	delete sam;
//	delete robot;
//	delete shu;
//	delete intern;
//	delete pres;
//	return 0;	
}

int	main()
{
	Intern	intern;
	AForm*	shrub;
	AForm*	robot;
	AForm*	president;
	AForm*	other;

	std::cout << std::endl;
	shrub = intern.makeForm("shrubberyCreation", "Bender");
	std::cout << std::endl;

	robot = intern.makeForm("robotomy request", "Fender");
	std::cout << std::endl;

	president = intern.makeForm("presidential pardon", "Zender");
	std::cout << std::endl;

	std::cout << "FAILED" << std::endl;
	try
	{
		other = intern.makeForm("unemployment notice", "Hender");
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	delete shrub;
	delete robot;
	delete president;
	delete other;
	return 0;
}

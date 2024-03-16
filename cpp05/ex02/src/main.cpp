/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:58:38 by bfiguet           #+#    #+#             */
/*   Updated: 2024/03/16 11:11:44 by bfiguet          ###   ########.fr       */
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

	try
	{
		Jam.executeAForm(shrubbery);
		Jam.executeAForm(robotomy);
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
		robotomy.beSigned(Jam);
		presidential.beSigned(Jam);
		Jam.executeAForm(shrubbery);
		Jam.executeAForm(robotomy);
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
		Jam.executeAForm(shrubbery);
		Jam.executeAForm(robotomy);
		Jam.executeAForm(presidential);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}

//int	main()
//{
//	std::cout << std::endl << "SHRUBBERY" << std::endl << std::endl;
//	try
//	{
//		ShrubberyCreationForm	shu;
//	}
//	catch (AForm::Exception& e)
//	{
//		std::cout << e.what();
//	}
//	std::cout << std::endl;
//	std::cout << std::endl;
//	try
//	{
//		ShrubberyCreationForm	shuTree("Tree");
//	}
//	catch (AForm::Exception& e)
//	{
//		std::cout << e.what();
//	}
//	std::cout << std::endl;
//	std::cout << std::endl;

//	std::cout << "Failed Exec" << std::endl;
//	Bureaucrat	sam("Sam", 5);
//	ShrubberyCreationForm	shuTree("Tree");
//	try
//	{
//		shuTree.execute(sam);
//	}
//	catch (AForm::Exception& e)
//	{
//		std::cout << e.what();
//	}
//	std::cout << std::endl;
//	std::cout << std::endl;

//	std::cout << "Failed Exec" << std::endl;
//	Bureaucrat	tom("Tom", 149);
//	std::cout << shuTree;
//	try
//	{
//		tom.executeAForm(shuTree);
//	}
//	catch (AForm::Exception& e)
//	{
//		std::cout << e.what();
//	}
//	std::cout << std::endl;
//	std::cout << std::endl;

//	std::cout << "Success" << std::endl;
//	std::cout << shuTree;
//	try
//	{
//		shuTree.beSigned(tom);
//	}
//	catch (AForm::Exception& e)
//	{
//		std::cout << e.what();
//	}
//	std::cout << std::endl;
//	std::cout << std::endl;

//	std::cout << "Failed Exec (too low)" << std::endl;
//	std::cout << tom;
//	std::cout << shuTree;
//	try
//	{
//		shuTree.execute(tom);
//	}
//	catch (AForm::Exception& e)
//	{
//		std::cout << e.what();
//	}
//	std::cout << std::endl;
//	std::cout << std::endl;

//	std::cout << "Failed Exec (too low)" << std::endl;
//	std::cout << tom;
//	std::cout << shuTree;
//	try
//	{
//		tom.executeAForm(shuTree);
//	}
//	catch (AForm::Exception& e)
//	{
//		std::cout << e.what();
//	}
//	std::cout << std::endl;
//	std::cout << std::endl;

//	std::cout << "Success" << std::endl;
//	try
//	{
//		shuTree.execute(sam);
//	}
//	catch (AForm::Exception& e)
//	{
//		std::cout << e.what();
//	}
//	std::cout << std::endl;
//	std::cout << std::endl;

//	std::cout << std::endl << "ROBOTOMY" << std::endl << std::endl;
//	try
//	{
//		RobotomyRequestForm	def;
//	}
//	catch (AForm::Exception& e)
//	{
//		std::cout << e.what();
//	}
//	std::cout << std::endl;
//	std::cout << std::endl;

//	try
//	{
//		RobotomyRequestForm	robot("Robot");
//	}
//	catch (AForm::Exception& e)
//	{
//		std::cout << e.what();
//	}
//	std::cout << std::endl;
//	std::cout << std::endl;

//	std::cout << "Failed Exec" << std::endl;
//	std::cout << sam;
//	RobotomyRequestForm	robot("Robot");
//	try
//	{
//		robot.execute(sam);
//	}
//	catch (AForm::Exception& e)
//	{
//		std::cout << e.what();
//	}
//	std::cout << std::endl;
//	std::cout << std::endl;

//	std::cout << "Failed Exec" << std::endl;
//	std::cout << sam;
//	std::cout << robot;
//	try
//	{
//		sam.executeAForm(robot);
//	}
//	catch (AForm::Exception& e)
//	{
//		std::cout << e.what();
//	}
//	std::cout << std::endl;
//	std::cout << std::endl;

//	std::cout << "Success" << std::endl;
//	std::cout << sam;
//	std::cout << robot;
//	try
//	{
//		robot.beSigned(sam);
//	}
//	catch (AForm::Exception& e)
//	{
//		std::cout << e.what();
//	}
//	std::cout << std::endl;
//	std::cout << std::endl;

//	std::cout << "Failed Exec (too low)" << std::endl;
//	std::cout << tom;
//	std::cout << robot;
//	try
//	{
//		robot.execute(tom);
//	}
//	catch (AForm::Exception& e)
//	{
//		std::cout << e.what();
//	}
//	std::cout << std::endl;
//	std::cout << std::endl;

//	std::cout << "Failed Exec (too low)" << std::endl;
//	std::cout << tom;
//	std::cout << robot;
//	try
//	{
//		tom.executeAForm(robot);
//	}
//	catch (AForm::Exception& e)
//	{
//		std::cout << e.what();
//	}
//	std::cout << std::endl;
//	std::cout << std::endl;

//	std::cout << "Success" << std::endl;
//	for(size_t i = 0; i < 6; i++)
//	{
//		try
//		{
//			robot.execute(tom);
//		}
//		catch (AForm::Exception& e)
//		{
//			std::cout << e.what();
//		}
//	}
//	std::cout << std::endl;
//	std::cout << std::endl;

//	std::cout << std::endl << "PRESIDENTIAL PARDON FORM" << std::endl << std::endl;
//	try
//	{
//		PresidentialPardonForm	p;
//	}
//	catch (AForm::Exception& e)
//	{
//		std::cout << e.what();
//	}
//	std::cout << std::endl;
//	std::cout << std::endl;

//	try
//	{
//		PresidentialPardonForm	president("President");
//	}
//	catch (AForm::Exception& e)
//	{
//		std::cout << e.what();
//	}
//	std::cout << std::endl;
//	std::cout << std::endl;

//	std::cout << "Failed Exec" << std::endl;
//	std::cout << sam;
//	PresidentialPardonForm	president("President");
//	try
//	{
//		president.execute(sam);
//	}
//	catch (AForm::Exception& e)
//	{
//		std::cout << e.what();
//	}
//	std::cout << std::endl;
//	std::cout << std::endl;

//	std::cout << "Failed Exec" << std::endl;
//	std::cout << sam;
//	std::cout << president;
//	try
//	{
//		sam.executeAForm(president);
//	}
//	catch (AForm::Exception& e)
//	{
//		std::cout << e.what();
//	}
//	std::cout << std::endl;
//	std::cout << std::endl;

//	std::cout << "Success" << std::endl;
//	std::cout << sam;
//	std::cout << president;
//	try
//	{
//		president.beSigned(sam);
//	}
//	catch (AForm::Exception& e)
//	{
//		std::cout << e.what();
//	}
//	std::cout << std::endl;
//	std::cout << std::endl;

//	std::cout << "Failed Exec (too low)" << std::endl;
//	std::cout << tom;
//	std::cout << president;
//	try
//	{
//		president.execute(tom);
//	}
//	catch (AForm::Exception& e)
//	{
//		std::cout << e.what();
//	}
//	std::cout << std::endl;
//	std::cout << std::endl;

//	std::cout << "Failed Exec (too low)" << std::endl;
//	std::cout << tom;
//	std::cout << president;
//	try
//	{
//		tom.executeAForm(president);
//	}
//	catch (AForm::Exception& e)
//	{
//		std::cout << e.what();
//	}
//	std::cout << std::endl;
//	std::cout << std::endl;

//	std::cout << "Success" << std::endl;
//	try
//	{
//		president.execute(sam);
//	}
//	catch (AForm::Exception& e)
//	{
//		std::cout << e.what();
//	}
//	std::cout << std::endl;
//	std::cout << std::endl;

//	return (0);
//}
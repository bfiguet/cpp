/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 11:36:30 by bfiguet           #+#    #+#             */
/*   Updated: 2024/02/29 16:00:24 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << "DEFAULT FORM" << std::endl;
	std::cout << std::endl;
	try
	{
		Form	def;
		std::cout << def << std::endl;
	}
	catch (Form::signException& e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;

	std::cout << "CORRECT FORM" << std::endl;
	std::cout << std::endl;
	try
	{
		Form	good("good", 15, 50);
		std::cout << good << std::endl;
	}
	catch (Form::signException& e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;

	std::cout << "FAILED SIGN" << std::endl;
	Bureaucrat	sam("sam", 88);
	Form	good("good", 15, 50);
	try
	{
		good.beSigned(sam);
	}
	catch (Form::signException& e)
	{
		std::cout << e.what();
	}
	sam.signForm(good);
	std::cout << std::endl;
	
	std::cout << "SUCCESSFUL SIGN" << std::endl;
	std::cout << std::endl;
	Bureaucrat	bob("Bob", 5);
	try
	{
		good.beSigned(bob);
	}
	catch (Form::signException& e)
	{
		std::cout << e.what();
	}
	bob.signForm(good);
	std::cout << std::endl;

	std::cout << "ReSign" << std::endl;
	Bureaucrat	mat("Mat", 10);
	try
	{
		good.beSigned(mat);
	}
	catch (Form::signException& e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
	
	std::cout << "FORM WITH EXECGRADE 151" << std::endl;
	std::cout << std::endl;
	try
	{
		Form	errform("errform", 50, 151);
	}
	catch (Form::signException& e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;

	std::cout << "FORM WITH SIGNGRADE 151" << std::endl;
	std::cout << std::endl;
	try
	{
		Form	errform("errform", 151, 50);
	}
	catch (Form::signException& e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;

	std::cout << "FORM WITH SIGNGRADE 0" << std::endl;
	std::cout << std::endl;
	try
	{
		Form	errform2("errform2", 0, 50);
	}
	catch (Form::signException& e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;

	std::cout << "FORM WITH EXECGRADE 0" << std::endl;
	std::cout << std::endl;
	try
	{
		Form	errform2("errform2", 50, 0);
	}
	catch (Form::signException& e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;

	return 0;
}
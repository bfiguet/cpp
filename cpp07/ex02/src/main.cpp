/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:58:21 by bfiguet           #+#    #+#             */
/*   Updated: 2024/04/03 20:26:31 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main(void){
	Array<int>		tab1;
	Array<int>		tab2(4);
	Array<int>		tabCpy(tab2);

	std::cout << "INT TAB2" << std::endl;
	for (size_t	i = 0; i < tab2.size(); i++)
	{
		try
		{
			tab2[i] = i + 1;
			std::cout << tab2[i] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << std::endl;

	std::cout << "INT TABCPY" << std::endl;
	tabCpy = tab2;
	for (size_t	i = 0; i < tabCpy.size(); i++)
	{
		try
		{
			std::cout << tabCpy[i] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << std::endl;

	std::cout << "tab1 size = " << tab1.size() << std::endl;
	std::cout << "tab2 size = " << tab2.size() << std::endl;
	std::cout << "tabCpy size = " << tabCpy.size() << std::endl;
	tab1 = tabCpy;
	std::cout << "tab1 size after copy tabCpy = " << tab1.size() << std::endl;
	
	std::cout << std::endl;
	std::cout << "ERR INDEX TAB2[5]" << std::endl;
	try
	{
		std::cout << tab2[5] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	Array<std::string>	str1;
	Array<std::string>	str2(4);
	Array<std::string>	strCpy(str2);
	std::cout << std::endl;

	std::cout << "STR2" << std::endl;
	for (size_t	i = 0; i < str2.size(); i++)
	{
		std::ostringstream	o;
		o << i + 1;
		try
		{
			str2[i] = o.str();;
			std::cout << str2[i] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << std::endl;

	std::cout << "STRCPY AFTER" << std::endl;
	strCpy = str2;
	for (size_t	i = 0; i < strCpy.size(); i++)
	{
		try
		{
			std::cout << strCpy[i] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << std::endl;

	std::cout << "str1 size = " << str1.size() << std::endl;
	std::cout << "str2 size = " << str2.size() << std::endl;
	std::cout << "strCpy size = " << strCpy.size() << std::endl;
	str1 = strCpy;
	std::cout << "str1 size after change = " << str1.size() << std::endl;
	std::cout << std::endl;

	std::cout << "ERR INDEX" << std::endl;
	try
	{
		std::cout << "str1 = " << str1[str1.size()] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	return 0;
}

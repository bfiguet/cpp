/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:32:35 by bfiguet           #+#    #+#             */
/*   Updated: 2023/12/14 13:45:21 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
	std::string const str = "HI THIS IS BRAIN";
	std::string const *stringPTR = &str;
	std::string const &stringREF = str;

	std::cout << "Memory address :" <<std::endl;
	std::cout << "str: \t\t" << &str << std::endl;
	std::cout << "stringPTR: \t" << stringPTR << std::endl;
	std::cout << "stringREF: \t" << &stringREF << std::endl;

	std::cout << "Value :" <<std::endl;
	std::cout << "str: \t\t" << str << std::endl;
	std::cout << "stringPTR: \t" << *stringPTR << std::endl;
	std::cout << "stringREF: \t" << stringREF << std::endl;

	return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 18:40:24 by bfiguet           #+#    #+#             */
/*   Updated: 2023/12/18 12:50:06 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main()
{
	Harl	harl;

	std::cout << "\nDEBUG" << std::endl;
	harl.complain("DEBUG");
	std::cout << "\nINFO" << std::endl;
	harl.complain("INFO");
	std::cout << "\nERROR" << std::endl;
	harl.complain("ERROR");
	std::cout << "\nWARNING" << std::endl;
	harl.complain("WARNING");
	std::cout << "\nTEST" << std::endl;
	harl.complain("TEST");
	return 0;
}

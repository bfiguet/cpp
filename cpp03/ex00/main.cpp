/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 18:31:07 by bfiguet           #+#    #+#             */
/*   Updated: 2023/12/20 20:37:39 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main()
{
	std::string trapName0 = "CT-00";
	std::string trapName1 = "CT-42";

	ClapTrap	trap0(trapName0);
	ClapTrap	trap1(trapName1);

	trap0.beRepaired(0);
	for (int i = 0; i < 9; i++) {
		trap0.attack(trapName1);
		trap1.takeDamage(0);
	}
	trap0.attack(trapName1);
	trap1.takeDamage(5);
	trap1.beRepaired(4);
	trap1.attack(trapName0);
	trap0.takeDamage(5);
	trap0.beRepaired(5000);
	trap1.beRepaired(5000);
	trap1.attack(trapName1);
	trap1.takeDamage(5000);
	trap1.beRepaired(5000);
	trap1.takeDamage(1);

	std::cout << "//// OTHER TESTS ////" << std::endl;
	ClapTrap a("David");
	ClapTrap b("Goliath");

	a.attack("some other robot");
	a.takeDamage(10);
	a.takeDamage(10);
	a.beRepaired(5);
	a.attack("some other other robot");
	b.beRepaired(3);
	b.beRepaired(3);
	return 0;
}

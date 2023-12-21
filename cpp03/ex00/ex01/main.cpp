/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 18:31:07 by bfiguet           #+#    #+#             */
/*   Updated: 2023/12/21 16:09:42 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main()
{
	ScavTrap a;
	ScavTrap b("Robot");

	a.attack("Robot");
	a.beRepaired(22);
	a.takeDamage(21);
	a.beRepaired(22);
	a.guardGate();
	a.guardGate();
	b.attack("SCVT");
	b.takeDamage(101);
	b.takeDamage(15);
	b.attack("SCVT");
	return 0;
}

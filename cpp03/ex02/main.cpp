/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 18:31:07 by bfiguet           #+#    #+#             */
/*   Updated: 2023/12/21 18:02:34 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main()
{
	FragTrap e;
	FragTrap f("NewRobot");

	e.highFivesGuys();
	e.attack("Robot");
	e.takeDamage(101);
	e.takeDamage(1);
	e.attack("Robot");
	f.highFivesGuys();
	return 0;
}

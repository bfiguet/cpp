/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 12:37:58 by bfiguet           #+#    #+#             */
/*   Updated: 2023/12/14 13:31:59 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name);

int	main()
{
	int	n;
	std::string name;

	std::cout << "How many zombies would you like create for your horde?\n> ";
	while (!(std::cin >> n) || n > 500 || n < 2)
	{
		if (std::cin.eof())
		{
			std::cout << "Error"<<std::endl;
			return 1;
		}
		std::cout << "Please enter number from 2 to 500"<<std::endl;
		std::cin.clear();
	}
	std::cout << "How do you called this horde?\n> ";
	std::cin.ignore();
	std::getline(std::cin, name);
	if (std::cin.eof() || name == "exit")
	{
		std::cout << "Thank's you! See you soon!"<<std::endl;
		return 1;
	}
	Zombie *horde = zombieHorde(n, name);
	std::cout << "you created " << n << " zombies in one time!" << std::endl;
	for (int i = 0; i < n; i++)
	{
		std::cout << i << ":";
		horde[i].announce();
	}
	delete []horde;
	return 0;
}

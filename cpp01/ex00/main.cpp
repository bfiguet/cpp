/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:16:47 by bfiguet           #+#    #+#             */
/*   Updated: 2023/12/14 12:35:55 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

//la pile/stack alloue memoire statiq lors d'un appel de fonction.
//le tas/heap alloue memoire dynamique a la demande du programme

void	randomChump(std::string name);
Zombie* newZombie(std::string name);

int main()
{
	std::string name;

	randomChump("Chump");
	while(1)
	{
		std::cout << "What's your name?\n> ";
		std::cin >> name;
		if (std::cin.eof() || name == "exit")
		{
			std::cout << "Thank's you! See you soon!"<<std::endl;
			return 1;
		}
		Zombie *yourZombie = newZombie(name);
		delete yourZombie;
	}
	return 0;
}
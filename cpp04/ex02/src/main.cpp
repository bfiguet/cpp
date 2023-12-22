/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 18:31:07 by bfiguet           #+#    #+#             */
/*   Updated: 2023/12/22 01:05:27 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"
# include <cstdlib>

int	main()
{
	const AAnimal	*meta[4];
	for (int i = 0; i < 4; i++)
	{
		if (i % 2) {
			meta[i] = new Cat();
			if (meta[i] == NULL)
				exit(1);
		}
		else {
			meta[i] = new Dog();
			if (meta[i] == NULL)
				exit (1);
		}
	}
	std::cout << std::endl;
	
	for (int i = 0; i < 4; i++)
	{
		std::cout << "_type: " << meta[i]->getType() << std::endl;
		meta[i]->makeSound();
		std::cout << std::endl;
	}
	std::cout << std::endl;
	
	for (int i = 0; i < 4; i++)
		delete(meta[i]);
	std::cout << std::endl;
	
	Dog *a = new Dog();
	if (a == NULL)
		exit(1);
	a->setIdea(0, "ueeeee");
	a->setIdea(1, "naaaaaan");
	a->setIdea(2, "prout");
	a->setIdea(101, "test");
	Dog *b = new Dog(*a);
	if (b == NULL)
		exit(1);
	std::cout << std::endl;
	
	std::cout << "The " << a->getType() << " a has the following ideas: " << std::endl;
	a->showIdea();
	std::cout << std::endl;
	
	delete(a);
	std::cout << std::endl;
	
	std::cout << "The " << b->getType() << " b has the following ideas: " << std::endl;
	b->showIdea();
	std::cout << std::endl;

	delete(b);
	return 0;
}

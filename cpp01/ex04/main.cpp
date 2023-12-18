/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:02:20 by bfiguet           #+#    #+#             */
/*   Updated: 2023/12/14 18:11:10 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "Error, we need ./ex04 <filename> <to_find> <to_replace>" << std::endl;
		return 1;
	}
	Replace replace(av[1]);
	replace.run_replace(av[2], av[3]);
	return 0;
}

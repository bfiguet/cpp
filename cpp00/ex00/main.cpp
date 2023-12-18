/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:29:31 by bfiguet           #+#    #+#             */
/*   Updated: 2023/12/18 12:33:48 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstring>

char	*ft_toupper(char *str, int i)
{
	while(str[++i])
		str[i] = std::toupper(str[i]);
	return (str);
}

int	main(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (1);
	}
	while (++i < ac)
			std::cout<< ft_toupper(av[i], -1);
		std::cout <<std::endl;
		return (0);
}

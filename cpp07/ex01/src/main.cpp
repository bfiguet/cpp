/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:22:19 by bfiguet           #+#    #+#             */
/*   Updated: 2024/03/19 13:40:15 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"

int main(){
	int			tabInt[5] = {12, 23, 34, 45, 56};
	std::string	tabStr[3] = {"Hello", "Coucou", "Hola"};
	const char	*tabStrCnst[3] = {"ab", "bc", "cd"};
	char		tabChar[5] = {'a', 'A', 'z', 'Z', '#'};
	char		str[15] = {"Hello friends!"};

	Iter(tabInt, 5, print);
	std::cout << std::endl;
	Iter(tabInt, 2, print);
	std::cout << std::endl;

	Iter(tabStr, 3, print);
	std::cout << std::endl;
	std::cout << std::endl;

	Iter(tabStrCnst, 3, print);
	std::cout << std::endl;
	std::cout << std::endl;

	Iter(tabChar, 5, print);
	std::cout << std::endl;

	Iter(str, 15, upper);
	std::cout << std::endl;
	return 0;
}

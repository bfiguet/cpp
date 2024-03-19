/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:38:29 by bfiguet           #+#    #+#             */
/*   Updated: 2024/03/19 16:03:13 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main(void){
	std::vector<int> a;

	a.push_back(1);
	a.push_back(2);
	a.push_back(3);

	std::cout << "SUCCESS" << std::endl;
	easyfind(a, 1);
	easyfind(a, 2);
	easyfind(a, 3);
	std::cout << std::endl;

	std::cout << "FAILED" << std::endl;
	easyfind(a, 0);
	easyfind(a, 4);
	easyfind(a, -1);
	easyfind(a, 42);
	std::cout << std::endl;

	return 0;
}

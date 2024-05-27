
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:34:16 by bfiguet           #+#    #+#             */
/*   Updated: 2024/03/27 12:34:49 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <vector>
#include <deque>
#include <ctime>
#include <iostream>
#include <string>
#include <stdexcept>

int main(int ac, char **av){
	clock_t		start;
	clock_t		end_vector;
	clock_t		end_dequ;
	std::string	str;
	std::vector<unsigned int> vec;
	std::deque<unsigned int> dequ;

	try{
		if (ac < 2)
			return 1;
		
		for(int i = 1; i < ac; ++i)
		{
			str += av[i];
			str += ' ';
		}
		
		start = clock();
		PmergeMe::sort(vec, str);
		end_vector = clock() - start;

		std::cout << "Before:\t";
		for (int i = 1; i < ac; ++i)
			std::cout << av[i] << " ";
		std::cout << std::endl;

		start = clock();
		PmergeMe::sort(dequ, str);
		end_dequ = clock() - start;

		std::cout << "After:\t";
		for (std::vector<unsigned int>::iterator it = vec.begin(); it != vec.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;

		std::cout << "Time to process a range of: " << vec.size() << " elements with std:: vector: " << (double)end_vector / CLOCKS_PER_SEC << "s" << std::endl;
		std::cout << "Time to process a range of: " << dequ.size() << " elements with std:: deque: " << (double)end_dequ / CLOCKS_PER_SEC << "s" << std::endl;

	} catch (std::exception &e) {
		std::cerr << "Error " << e.what() << std::endl;
		return 1;
	}
	return 0;
}

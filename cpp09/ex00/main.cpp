/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:55:23 by bfiguet           #+#    #+#             */
/*   Updated: 2024/03/21 19:11:03 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av){
	if (ac != 2)
		std::cout << ERR_ARG << std::endl;
	else{
		BitcoinExchange btc;
		if (btc.getErr() == false){
			try {
				btc.executebtc(av[1]);
			} catch (const std::exception& e){
				std::cout << e.what() << std::endl;
			}
		}
	}
	return 0;
}

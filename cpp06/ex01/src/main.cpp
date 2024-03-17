/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:17:29 by bfiguet           #+#    #+#             */
/*   Updated: 2024/03/17 16:41:33 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(){
	Data	data = {.val = 42};
	uintptr_t	seri = Serializer::serialize(&data);
	Data		*des = Serializer::deserialize(seri);

	std::cout << "Data.val = " << data.val << std::endl;
	std::cout << "Serialized Data = " << seri << std::endl;
	std::cout << "Deserialized Data = " << des->val << std::endl;
	std::cout <<std::endl;
	data.val = 0;
	std::cout << "Data.val = " << data.val << std::endl;
	std::cout << "Serialized Data = " << seri << std::endl;
	std::cout << "Deserialized Data = " << des->val << std::endl;
	std::cout <<std::endl;
	data.val = 100;
	std::cout << "Data.val = " << data.val << std::endl;
	std::cout << "Serialized Data = " << seri << std::endl;
	std::cout << "Deserialized Data = " << des->val << std::endl;
	std::cout <<std::endl;

	return  0;
}
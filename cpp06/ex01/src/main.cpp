/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:17:29 by bfiguet           #+#    #+#             */
/*   Updated: 2024/03/18 12:34:31 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(){
	Data	data = {.intVal = 42};
	uintptr_t	seri = Serializer::serialize(&data);
	Data		*des = Serializer::deserialize(seri);

	std::cout << "Data.val = " << data.intVal << std::endl;
	std::cout << "Serialized Data = " << seri << std::endl;
	std::cout << "Deserialized Data = " << des->intVal << std::endl;
	std::cout <<std::endl;
	data.intVal = 0;
	std::cout << "Data.val = " << data.intVal << std::endl;
	std::cout << "Serialized Data = " << seri << std::endl;
	std::cout << "Deserialized Data = " << des->intVal << std::endl;
	std::cout <<std::endl;
	data.intVal = 100;
	std::cout << "Data.val = " << data.intVal << std::endl;
	std::cout << "Serialized Data = " << seri << std::endl;
	std::cout << "Deserialized Data = " << des->intVal << std::endl;
	std::cout <<std::endl;

	Data	data2 = {.charVal = 'a'};
	uintptr_t	seri2 = Serializer::serialize(&data2);
	Data		*des2 = Serializer::deserialize(seri2);

	std::cout << "Data.val = " << data2.charVal << std::endl;
	std::cout << "Serialized Data = " << seri2 << std::endl;
	std::cout << "Deserialized Data = " << des2->charVal << std::endl;
	std::cout <<std::endl;
	data2.charVal = 'A';
	std::cout << "Data.val = " << data2.charVal << std::endl;
	std::cout << "Serialized Data = " << seri2 << std::endl;
	std::cout << "Deserialized Data = " << des2->charVal << std::endl;
	std::cout <<std::endl;
	data2.charVal = '#';
	std::cout << "Data.val = " << data2.charVal << std::endl;
	std::cout << "Serialized Data = " << seri2 << std::endl;
	std::cout << "Deserialized Data = " << des2->charVal << std::endl;
	std::cout <<std::endl;

	return  0;
}
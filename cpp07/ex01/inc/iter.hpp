/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:20:05 by bfiguet           #+#    #+#             */
/*   Updated: 2024/03/19 15:40:23 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP
#include <string>
#include <iostream>
//#include <cstring>

template<typename T>

void	Iter(T* tab, size_t len, void(*func)(T&)){
	for (size_t i = 0; i < len; i++)
		func(tab[i]);
}

template<typename T>
void	print(T &val){
	std::cout << val << " .";
}

void	upper(char &str){
	str = toupper(str);
	std::cout << str;
}

#endif
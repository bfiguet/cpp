/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:20:05 by bfiguet           #+#    #+#             */
/*   Updated: 2024/04/03 20:30:02 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP
#include <iostream>

template<typename T>
void	iter(T* tab, const size_t len, void(*func)(T&)){
	for (size_t i = 0; i < len; i++)
		func(tab[i]);
}

template<typename T>
void	iter(const T* tab, const size_t len, void(*func)(const T&)){
	for (size_t i = 0; i < len; i++)
		func(tab[i]);
}

template<typename T>
void	printT(T &val){
	std::cout << val << " .";
}

void	upper(char &str){
	str = toupper(str);
	std::cout << str;
}

#endif

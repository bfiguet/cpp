/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:38:58 by bfiguet           #+#    #+#             */
/*   Updated: 2024/03/19 16:04:06 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
void	easyfind(T& t, int i){
	typename T::iterator it = std::find(t.begin(), t.end(), i);
	if (it != t.end())
		std::cout << i << " was found" << std::endl;
	else
		std::cout << i << " wasn't found" << std::endl;
}

#endif
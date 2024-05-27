/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:26:57 by bfiguet           #+#    #+#             */
/*   Updated: 2024/05/27 21:12:47 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP


#include <iostream>
#include <sstream>
#include <string>


class PmergeMe
{
private:
	PmergeMe(PmergeMe const &src);
	PmergeMe & operator=(PmergeMe const & src);

public:
	PmergeMe();
	~PmergeMe();

	template<typename T>
	static void sort(T& container, const std::string& str);
};
#include "PmergeMe.tpp"
#endif
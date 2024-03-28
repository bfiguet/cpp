/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:26:57 by bfiguet           #+#    #+#             */
/*   Updated: 2024/03/28 15:28:20 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <algorithm>
#include <ctime>
#include <vector>
#include <list>

template <template<typename, typename> class Container>
class PmergeMe
{
private:
	Container<int, std::allocator<int> >	_before;
	Container<int, std::allocator<int> >	_after;
	int										_size;

	PmergeMe(void);
	PmergeMe(PmergeMe const &src);
	PmergeMe & operator=(PmergeMe const &src);
	
public:
	PmergeMe(char **av);
	~PmergeMe(void){};

	void	sort(void);
	void	printRes(void)const;
	class Err: public std::exception{
		private:
			const char*	_str;
		public:
			Err(const char* str): _str(str){};
			const char* what() const throw(){return _str;};
	};
};

#include "PmergeMe.cpp"

#endif
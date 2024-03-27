/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:26:57 by bfiguet           #+#    #+#             */
/*   Updated: 2024/03/27 12:35:03 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <string>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <vector>
#include <list>

class PmergeMe
{
private:
std::vector<unsigned int>	_tab;
	PmergeMe(PmergeMe const &src);
	PmergeMe & operator=(PmergeMe const & src);

public:
	PmergeMe(int ac, char **av);
	PmergeMe(PmergeMe const &src);
	PmergeMe & operator=(PmergeMe const & src);
	~PmergeMe();

	void	vectorMethod();
	void	listMethod(int ac, char **av);

	class Err: public std::exception{
		private:
			const char*	_str;
		public:
			Err(const char* str): _str(str){};
			const char* what() const throw(){return _str;};
	};
};

#endif
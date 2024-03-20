/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:41:09 by bfiguet           #+#    #+#             */
/*   Updated: 2024/03/20 13:02:36 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP
#include <iostream>
# include <algorithm>
# include <vector>
# include <limits>
# include <cstdlib>

class Span
{
private:
	size_t				_n;
	std::vector<long>	_tab;

public:
	Span();
	Span(size_t const n);
	Span(Span const & cpy);
	~Span();

	Span & operator=(Span const &src);

	size_t				getN()const;
	std::vector<long>	getTab()const;
	size_t				getSpan(long const n1, long const n2);

	void				addNumber(int const n);
	void				addNums();
	std::vector<long>	initFunc(std::vector<long>sort);
	size_t				shortestSpan();
	size_t				longestSpan();

	class noSpan : public std::exception{
		public:
			const char* what() const throw(){ return "Error: Need more than one number.";};
	};

	class noAdd : public std::exception{
		public:
			const char* what() const throw(){ return "Error: Capacity is full.";};
	};
};

#endif
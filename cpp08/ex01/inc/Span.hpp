/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:41:09 by bfiguet           #+#    #+#             */
/*   Updated: 2024/03/19 16:20:55 by bfiguet          ###   ########.fr       */
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
	Span(): _n(0), _tab(0){};
	Span(size_t const n): _n(n), _tab(0){};
	Span(Span const & cpy){*this = cpy;};
	~Span();

	Span& operator=(Span const & src);

	size_t				getN()const{return _n;};
	std::vector<long>	getTab()const{return _tab;};
	size_t				getSpan(long const n1, long const n2);

	void				addNumber(int const n);
	void				addNums();
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
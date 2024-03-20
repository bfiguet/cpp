/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:41:31 by bfiguet           #+#    #+#             */
/*   Updated: 2024/03/20 13:12:16 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(): _n(0), _tab(0){};
Span::Span(size_t const n): _n(n), _tab(0){};
Span::Span(Span const & cpy){*this = cpy;};
Span::~Span(){};

Span & Span::operator=(Span const &src){
	if (this != &src){
		_n = src._n;
		_tab = src._tab;
	}
	return *this;
}

size_t	Span::getN()const{return _n;};

std::vector<long>	Span::getTab()const{return _tab;};

size_t	Span::getSpan(long const n1, long const n2){
	if (n1 > n2)
		return (n1 - n2);
	return (n2 - n1);
}

void	Span::addNumber(int const n){
	if (_tab.size() >= _n)
		throw Span::noAdd();
	_tab.push_back(n);
}

void	Span::addNums(){
	if (_tab.size() >= _n)
		throw Span::noAdd();
	try {
		for (size_t i = 0; i < _n; i++){
			long n = static_cast<long>(std::rand());
			_tab.push_back(n);
		}
	} catch (const std::exception& e){
		std::cout << e.what() << std::endl;
	}
}

std::vector<long> 	Span::initFunc(std::vector<long> tab){
	if (_tab.size() < 2)
		throw Span::noSpan();
	std::sort(tab.begin(), tab.end());
	return tab;
}

size_t	Span::shortestSpan(){
	std::vector<long>	tab = initFunc(_tab);
	size_t	ret = tab[1] - tab[0];
	for (size_t i = 1; i < tab.size(); i++)
		size_t(tab[i] - tab[i - 1]) < ret ? ret = (tab[i] - tab[i - 1]) : ret;
	return ret;
}

size_t	Span::longestSpan(){
	std::vector<long>	tab = initFunc(_tab);
	return (static_cast<size_t>(tab.back() - tab.front()));
}

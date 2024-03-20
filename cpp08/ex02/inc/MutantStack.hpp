/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:42:17 by bfiguet           #+#    #+#             */
/*   Updated: 2024/03/20 17:20:21 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <list>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack(){};
	MutantStack(MutantStack const & cpy){*this = cpy;};
	~MutantStack(){};

	typedef typename std::stack<T>::container_type::iterator iterator;
	iterator begin(){return this->c.begin();};
	iterator end(){return this->c.end();};

	typedef typename std::stack<T>::container_type::const_iterator	constIterator;
	constIterator begin()const{return this->c.begin();};
	constIterator end()const{return this->c.end();};
};

#endif
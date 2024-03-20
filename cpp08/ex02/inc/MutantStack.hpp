/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:42:17 by bfiguet           #+#    #+#             */
/*   Updated: 2024/03/20 13:34:02 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <list>
#include <vector>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack(){};
	MutantStack(MutantStack const & cpy){*this = cpy;};
	~MutantStack(){};

	MutantStack & operator=(MutantStack const & src){
		this = &src;
		return *this;
	};

	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator constIterator;

	iterator		begin(){return this->c.begin();};
	iterator		end(){return this->c.end();};
	constIterator	begin()const{return this->c.begin();};
	constIterator	end()const{return this->c.end();};
};

#endif
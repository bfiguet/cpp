/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:57:44 by bfiguet           #+#    #+#             */
/*   Updated: 2024/04/03 20:30:08 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <sstream>

template<typename T>
class Array
{
private:
	T*				_arr;
	unsigned int	_len;
public:
	Array(void): _arr(new T[0]), _len(0){};
	Array(const unsigned int n): _arr(new T[n]), _len(n){};
	Array(Array const &src ) : _arr(new T[src._len]), _len(src._len) {*this = src;};
	~Array(void){ delete [] _arr;};

	Array & operator=(Array const & src){
		if (_len != src._len){
			delete [] _arr;
			_len = src._len;
			_arr = new T[_len];
		}
		for (unsigned int i = 0; i < _len; i++)
			_arr[i] = src._arr[i];
		return *this;
	};

	class tooHigh : public std::exception{
		public:
			virtual const char* what() const throw(){
				return ("Index is too high");
			};
	};
	T & operator[](const unsigned int i){
		if (i >= _len)
			throw Array::tooHigh();
		return _arr[i];
	};

	unsigned int	size(void) const{
		return _len;
	};
};

#endif
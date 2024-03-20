/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:57:44 by bfiguet           #+#    #+#             */
/*   Updated: 2024/03/20 11:24:28 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <string>
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
	Array(unsigned int n): _arr(new T[n]), _len(n){};
	Array(Array const &src ) : _arr(new T[src._len]), _len(src._len) {*this = src;};
	~Array(void){ delete [] _arr;};

	Array & operator=(Array const & src){
		if (this->_len != src._len){
			delete [] _arr;
			this->_len = src._len;
			this->_arr = new T[this->_len];
		}
		for (unsigned int i = 0; i < this->_len; i++)
			this->_arr[i] = src._arr[i];
		return *this;
	};

	class tooHigh : public std::exception{
		public:
			virtual const char* what() const throw(){
				return ("Index is too high");
			};
	};
	T & operator[](unsigned int i){
		if (i >= this->_len)
			throw Array::tooHigh();
		return this->_arr[i];
	};

	unsigned int	size(void) const{
		return this->_len;
	};
};

#endif
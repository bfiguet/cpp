/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:34:24 by bfiguet           #+#    #+#             */
/*   Updated: 2024/03/27 10:28:23 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>
#include <cstdlib>
#include <iostream>
#include <sstream>

class RPN
{
private:
	RPN();
	void	resolvOp(char* const av)const;
public:
	RPN(int const ac, char* const val);
	~RPN();

	class Err: public std::exception{
		private:
			const char*	_str;
		public:
			Err(const char* str): _str(str){};
			const char* what() const throw(){return _str;};
	};
};

#endif
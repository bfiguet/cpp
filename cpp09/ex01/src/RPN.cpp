/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:50:01 by bfiguet           #+#    #+#             */
/*   Updated: 2024/04/22 11:08:02 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(){}
RPN::RPN(RPN const & src){*this = src;}
RPN &RPN::operator=(RPN const & src){
	(void) &src;
	return *this;}
RPN::RPN(int const ac, char* const av){
	if (ac != 2)
		throw RPN::Err("Error:  Invalid number of arguments.");
	resolvOp(av);
}
RPN::~RPN(){}

void	RPN::resolvOp(char* const av)const{
	std::stack<int>		stack;
	std::istringstream	iss(av);
	std::string			str;

	while (iss >> str)
	{
		//std::cout << "str=" << str << std::endl;
		if (isdigit(str[0]) || (str[0] == '-' && str.size() > 1 && isdigit(str[1])))
			stack.push(std::atoi(str.substr(0, 1).c_str()));
		else if (str[0] != '+' && str[0] != '-' && str[0] != '*' && str[0] != '/')
			throw RPN::Err("Invalid char");
		else {
			if (stack.size() >= 2){
				int	val1 = stack.top();
				stack.pop();
				int	val2 = stack.top();
				stack.pop();
				//std::cout << "val1=" << val1 << ", val2=" << val2 << std::endl;
				switch (str[0]){
					case '+':
						stack.push(val2 + val1);
						break;
					case '-':
						stack.push(val2 - val1);
						break;
					case '*':
						stack.push(val2 * val1);
						break;
					case '/':
						if (val1 == 0 || val2 == 0)
							throw RPN::Err("Division with zero");
						else
							stack.push(val2 / val1);
						break;
					default:
						throw RPN::Err("Invalid operator");
				}
			}
		}
	}
	if (!stack.empty())
		std::cout << stack.top() << std::endl;
	else
		throw RPN::Err("Empty Stack");
}

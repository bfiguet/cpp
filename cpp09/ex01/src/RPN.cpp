/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:50:01 by bfiguet           #+#    #+#             */
/*   Updated: 2024/04/22 20:54:09 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(){}
RPN::RPN(RPN const & src){*this = src;}
RPN &RPN::operator=(RPN const & src){
	(void) &src;
	return *this;}
//RPN::RPN(int const ac, char* const av){
//	if (ac != 2)
//		throw RPN::Err("Error:  Invalid number of arguments.");
//	resolvOp(av);
//}
RPN::~RPN(){}

RPN::RPN(int ac, char * av){
	if (ac != 2)
		throw RPN::Err("Error:  Invalid number of arguments.");
	parseAv(av);
}
static bool isOp(char c){
	if (c == '+' || c == '-' || c == '/' || c == '*')
		return true;
	return false;
}

static std::stack<int> resolvOp(std::stack<int> stack, char c){
	if (stack.empty())
		throw RPN::Err("Invalid size");
	if (stack.size() >= 2){
		int	val1 = stack.top();
		stack.pop();
		int	val2 = stack.top();
		stack.pop();
		switch (c)
		{
			case '+':
				stack.push(val2 + val1);
				break;
			case '-':
				stack.push(val2 - val1);
				break;
			case '/':
				if (val1 == 0 || val2 == 0)
					throw RPN::Err("Division with zero");
				stack.push(val2 / val1);
				break;
			case '*':
				stack.push(val2 * val1);
				break;
			default:
				throw RPN::Err("Invalid operator");
		}
	}
	else
		throw RPN::Err("Invalid value");
	return stack;
}

void	RPN::parseAv(std::string av){
	std::stack<int>		stack;
	
	for (size_t i = 0; i < av.size(); i++){
		while (av[i] == ' ')
			i++;
		if (!isdigit(av[i]) && !isOp(av[i]))
			throw RPN::Err("Invalid char");
		if ((isdigit(av[i]) || isOp(av[i + 1])) && av[i + 1] && !isspace(av[i + 1]))
			throw RPN::Err("Invalid input");
		if (isdigit(av[i]))
			stack.push(av[i] - '0');
		if (isOp(av[i]))
			stack = resolvOp(stack, av[i]);
	}
	if (stack.size() != 1)
		throw RPN::Err("Invalid size");
	std::cout << stack.top() << std::endl;
}

//void	RPN::resolvOp(char* const av)const{
//	std::stack<int>		stack;
//	std::istringstream	iss(av);
//	std::string			str;
	
//	while (iss >> str)
//	{
//		if (str[1] && (isalpha(str[1]) || isdigit(str[1])))
//			throw RPN::Err("Invalid input");
//		if (isdigit(str[0]) || (str[0] == '-' && str.size() > 1 && isdigit(str[1])))
//			stack.push(std::atoi(str.substr(0, 1).c_str()));
//		else if (str[0] != '+' && str[0] != '-' && str[0] != '*' && str[0] != '/')
//			throw RPN::Err("Invalid char");
//		else {
//			if (stack.size() >= 2){
//				int	val1 = stack.top();
//				stack.pop();
//				int	val2 = stack.top();
//				stack.pop();
//				//std::cout << "val1=" << val1 << ", val2=" << val2 << std::endl;
//				if (isdigit(val1) && isdigit(val2))
//					throw RPN::Err("Invalid input");
//				switch (str[0]){
//					case '+':
//						stack.push(val2 + val1);
//						break;
//					case '-':
//						stack.push(val2 - val1);
//						break;
//					case '*':
//						stack.push(val2 * val1);
//						break;
//					case '/':
//						if (val1 == 0 || val2 == 0)
//							throw RPN::Err("Division with zero");
//						else
//							stack.push(val2 / val1);
//						break;
//					default:
//						throw RPN::Err("Invalid operator");
//				}
//			}
			
//		}
//	}
//	if (!stack.empty())
//		std::cout << stack.top() << std::endl;
//	else
//		throw RPN::Err("Empty Stack");
//}

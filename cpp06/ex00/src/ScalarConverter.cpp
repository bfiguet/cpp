/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 21:38:02 by bfiguet           #+#    #+#             */
/*   Updated: 2024/03/18 12:27:55 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

std::string	printChar(char c){
	if (c >= 33 && c <= 126){
		std::cout << c;
		return "";
	}
	return "Non displayable";
}

std::string	printFloat(float f){
	std::cout << f;
	if (!(std::abs(f - trunc(f)) < 1e-5) && !(std::abs(f - trunc(f)) < 1e-4))
		return "f";
	return ".0f";
}

std::string	printDouble(double d){
	std::cout << d;
	if (!(std::abs(d - trunc(d)) < 1e5) && !(std::abs(d - trunc(d)) < 1e-4))
		return "";
	return ".0";
}

void	convInt(int nb){
	std::cout << "char : " << printChar(static_cast<char>(nb)) << std::endl;
	std::cout << "int : " << nb << std::endl;
	std::cout << "float : " << printFloat(static_cast<float>(nb)) << std::endl;
	std::cout << "double : " << printDouble(static_cast<double>(nb)) << std::endl;
}

void	convFloat(float f){
	std::cout << "char : " << printChar(static_cast<char>(f)) << std::endl;
	std::cout << "int : " << static_cast<int>(f) << std::endl;
	std::cout << "float : " << printFloat(f) << std::endl;
	std::cout << "double : " << printDouble(static_cast<double>(f)) << std::endl;
}

void	convDouble(double d){
	std::cout << "char : " << printChar(static_cast<char>(d)) << std::endl;
	std::cout << "int : " << static_cast<int>(d) << std::endl;
	std::cout << "float : " << printFloat(static_cast<float>(d)) << std::endl;
	std::cout << "double : " << printDouble(static_cast<double>(d)) << std::endl;
}

void	convChar(char c){
	std::cout << "char : " << c << std::endl;
	std::cout << "int : " << static_cast<int>(c) << std::endl;
	std::cout << "float : " << printFloat(static_cast<float>(c)) << std::endl;
	std::cout << "double : " << printDouble(static_cast<double>(c)) << std::endl;
}

bool	isFloat(const std::string& str){
	char* ptr;
	if (str.empty() || str.find(".") == std::string::npos || str.find("f") - 1 == str.find("."))
		return false;
	strtod(str.c_str(), &ptr);
	return (*ptr == 'f' && errno != ERANGE);
}

bool	isDouble(const std::string& str){
	char* ptr;
	if (str.empty() || str.find(".") == std::string::npos || str.find(".") + 1 == str.length())
		return false;
	strtod(str.c_str(), &ptr);
	return (*ptr == '\0');
}

bool	isInt(const std::string& str){
	char* ptr;
	if (str.empty())
		return false;
	strtol(str.c_str(), &ptr, 10);
	return (*ptr == '\0');
}

bool	isChar(const std::string& str){
	return str.length() == 1;
}

void	ScalarConverter::converter(const std::string &str){
	char*	ptr;
	if (str == "nan" || str == "nanf" || str == "+inf" || str == "-inf"){
		std::cout << "char : impossible" << std::endl;
		if (str == "nan" || str == "nanf"){
			std::cout << "int : impossible" << std::endl;
			std::cout << "float : nanf" << std::endl;
			std::cout << "double : nan" << std::endl;
		}
		if (str == "+inf" || str == "-inf"){
			std::cout << "int : " << str << std::endl;
			std::cout << "float : " << str << std::endl;
			std::cout << "double : " << str << std::endl;
		}
		return ;
	}
	if (isFloat(str))
		convFloat(strtof(str.c_str(), &ptr));
	else if (isDouble(str))
		convDouble(strtof(str.c_str(), &ptr));
	else if (isInt(str))
		convInt(strtof(str.c_str(), &ptr));
	else if (isChar(str))
		convChar(strtof(str.c_str(), &ptr));
	else
		std::cout << "not valid" << std::endl;
}

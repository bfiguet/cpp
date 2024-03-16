/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 20:44:27 by bfiguet           #+#    #+#             */
/*   Updated: 2024/03/17 00:02:39 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

# include <iostream>
# include <cmath>
# include <cerrno>
# include <cstdlib>

class ScalarConverter
{
public:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &cpy);
	~ScalarConverter();

	ScalarConverter&	operator=(const ScalarConverter &src);
	static void			converter(const std::string &str);	
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 20:44:27 by bfiguet           #+#    #+#             */
/*   Updated: 2024/03/20 11:25:08 by bfiguet          ###   ########.fr       */
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
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &cpy);
	~ScalarConverter();

	ScalarConverter&	operator=(const ScalarConverter &src){(void)src; return *this;};
public:	
	static void			converter(const std::string &str);	
};

#endif
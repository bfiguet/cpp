/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:51:14 by bfiguet           #+#    #+#             */
/*   Updated: 2024/03/23 18:49:46 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip> 
#include <limits>

# define DATA "data.csv"

#define ERR_ARG					"Need 1 argument like ./btc input.txt"
#define	EMPTY_FIE				"File is empty"
#define	WRONG_FILE				"File format is wrong"
#define	INVALID_VAL				"invalid value in file"
#define INVALID_DATE			"invalid date in file"
#define NOT_OPEN				"File couldn't be opened"
#define BAD_INPUT				"bad file input"
class BitcoinExchange
{
private:
	std::map<std::string, std::string>	_data;
	bool								_err;

	bool								isValidDate(std::string const &date);
	bool								isValidVal(std::string const &val);
	std::string							getVal(std::string const &date);
	void								checkFile(std::string file);
	void								printErr(const char* str);
public:
	BitcoinExchange();
	BitcoinExchange(BitcoinExchange const &cpy);
	~BitcoinExchange();

	BitcoinExchange & 					operator=(BitcoinExchange const &src);

	std::map<std::string, std::string>	setData();
	std::map<std::string, std::string>	getData() const;
	void								execBtc(std::string const &file);
	bool								getErr()const;

	class Err: public std::exception{
		private:
			const char*	_str;
		public:
			Err(const char* str): _str(str){};
			const char* what() const throw(){return _str;};
	};
};

#endif
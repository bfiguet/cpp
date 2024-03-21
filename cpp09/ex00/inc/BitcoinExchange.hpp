/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:51:14 by bfiguet           #+#    #+#             */
/*   Updated: 2024/03/21 19:11:45 by bfiguet          ###   ########.fr       */
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

#define DATA "data.csv"
//#define SEP ","
#define PIPE "|"

#define ERR_ARG					"Need 1 argument like ./btc input.txt"
#define	EMPTY_FIE				"File is empty"
#define	WRONG_FILE				"File format is wrong"
#define	INVALID_VAL				"invalid value in file"
#define INVALID_DATE			"invalid date in file"
#define NOT_OPEN				"File couldn't be opened"
#define BAD_INPUT				"bad file input"
//#define NO_DATE					"no data for this date"
//#define NEG_NUM					"not a positive number"
//#define TOO_LARGE				"too large a number"

class BitcoinExchange
{
private:
	//std::string							_fileName;
	//std::ifstream						_file;
	//std::ifstream						_db;
	std::map<std::string, std::string>	_data;
	bool								_err;
	
	bool								isValidDate(std::string const & date);
	void								printDb(std::map<std::string, std::string> & data);
	bool								isValidVal(std::string const val);
	std::string							getVal(std::string const & date);
	std::string							previousDate(std::string const & date);					
	void								printErr(std::string str);
public:
	BitcoinExchange();
	BitcoinExchange(BitcoinExchange const &copy);
	~BitcoinExchange();

	BitcoinExchange & 					operator=(BitcoinExchange const & src);

	std::map<std::string, std::string>	setData();
	std::map<std::string, std::string>	getData() const;
	void								execBtc(std::string const & file);
	bool								getErr()const;

	class Err: public std::exception{
		public:
			const char* what() const throw(){return std::string;};
	};
};

#endif
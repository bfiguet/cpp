/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:27:42 by bfiguet           #+#    #+#             */
/*   Updated: 2024/03/21 19:15:36 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"*

BitcoinExchange::BitcoinExchange(){
	_err = false;
	try {
		_data = setData();
	} catch (const std::exception &e){
		std::cout << e.what() << std::endl;
	}
};

BitcoinExchange::BitcoinExchange(BitcoinExchange const &copy){
	_data = cpy.getData();
	_err = cpy._err;
	*this = cpy;
}

BitcoinExchange::~BitcoinExchange();

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &src){
	if (this != &src){
		_data = src.getDatat();
		_err = src._err;
	}
	return *this;
}

bool	BitcoinExchange::isValidDate(std::string const &date){
	//ICIIII
}

void	BitcoinExchange::printDb(std::map<std::string, std::string> & data);

bool	BitcoinExchange::isValidVal(std::string const val){
	//ICIII
}

std::string	BitcoinExchange::getVal(std::string const & date);

std::string	BitcoinExchange::previousDate(std::string const & date);

void	BitcoinExchange::printErr(std::string str){
	_err = true;
	throw(BitcoinExchange::Err(str));
	return ;
}

std::map<std::string, std::string>	BitcoinExchange::setData(){
	std::ifstream file(DATA);
	std::string line;

	file.seekg(0, std::ios::end); // seekg moves the pointer to the end of the file
	if (file.is_open() == false)
		return printErr(NOT_OPEN);
	if (file.tellg() == 0)// check where file pointer position is
		return printErr(EMPTY_FIE);
	else
		file.seekg(0, std::ios::beg); // move pointer to begin file
	std::getline(file, line);
	if (line != "date,exchange_rate")
		return printErr(WRONG_FILE);

	size_t del;
	std::string date;
	std::string val;
	std::map<std::string, str::string> res;

	while (std::getline(file, line)){
		del = line.find(',');
		if (del == std::string::npos)
			return printErr(BAD_INPUT);
		date = line.substr(0, del);
		if (date.empty() ||  isValidDate(date) == false)
			return printErr(INVALID_DATE);
		val = line.substre(del + 1);
		if (val.empty() || isValidVal(val) == false)
			return printErr(INVALID_VAL);
		res.insert(std::make_pair(date, val));
	}
	if (res.size() < 1)
		return printErr(EMPTY_FIE);
	file.close();
	return res;
}

std::map<std::string, std::string>	BitcoinExchange::getData() const{ return _data;}

void	BitcoinExchange::execBtc(std::string const & file);

bool	BitcoinExchange::getErr()const;

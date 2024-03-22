/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:27:42 by bfiguet           #+#    #+#             */
/*   Updated: 2024/03/22 15:14:50 by bfiguet          ###   ########.fr       */
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

void	BitcoinExchange::printErr(std::string str){
	_err = true;
	throw(BitcoinExchange::Err(str));
	return ;
}

bool	BitcoinExchange::isValidDate(std::string const &date){
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;
	int year = atoi((date.substr(0,4)).c_str());
	int month = atoi((date.substr(5,2)).c_str());
	int	day = atoi((date.substr(8,2)).c_str());

	if (year < 2009 || year > 2024)
		return false;
	if (month < 1 || month > 12)
		return false;
	if (day < 1 || day > 31)
		return false;
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return false;
	if (month == 2 && (year == 2016 || year == 2020 || year == 2024) && day > 29)
		return false;
	if (month == 2 && (year != 2016 || year != 2020 || year != 2024) && day > 28)
		return false;
	return true;
}

bool	BitcoinExchange::isValidVal(std::string const val){
	if (isdigit(val.c_str()))
		return true;
	return false;
}

std::string	BitcoinExchange::getVal(std::string const & date){
	std::map<std::string, std::string>::const_iterator it;
	std::string res;

	it = _data.find(date);
	if (it != _data.end())
		return (*it).second;
	else{
		std::string prevDate = previousDate(date);
		return getVal(prevDate);
	}
}

bool	BitcoinExchange::getErr()const{return _err};

std::string	BitcoinExchange::previousDate(std::string const &date){
	
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


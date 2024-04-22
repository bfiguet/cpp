/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:27:42 by bfiguet           #+#    #+#             */
/*   Updated: 2024/04/22 19:00:44 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){
	_err = false;
	try {
		_data = setData();
	} catch (const std::exception &e){
		std::cout << e.what() << std::endl;
	}
};

BitcoinExchange::BitcoinExchange(BitcoinExchange const &cpy){
	_data = cpy.getData();
	_err = cpy._err;
	*this = cpy;
}

BitcoinExchange::~BitcoinExchange(){};

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &src){
	if (this != &src){
		_data = src.getData();
		_err = src._err;
	}
	return *this;
}

void	BitcoinExchange::printErr(const char* str){
	_err = true;
	throw(BitcoinExchange::Err(str));
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
	if (month == 2 && (year == 2012 || year == 2016 || year == 2020 || year == 2024) && day > 29)
		return false;
	if (month == 2 && (year != 2012 && year != 2016 && year != 2020 && year != 2024) && day > 28)
		return false;
	return true;
}

bool	BitcoinExchange::isValidVal(std::string const &val){
	std::istringstream iss(val);
	float n;
	iss >> n;
	return iss.eof() && !iss.fail();
}

std::map<std::string, std::string>	BitcoinExchange::getData() const{ return _data;}

std::string	BitcoinExchange::getVal(std::string const &date){
	std::map<std::string, std::string>::const_iterator it;

	it = _data.find(date);
	if (it != _data.end())
		return (*it).second;
	else{
		std::string	prev = "";
		for (std::map<std::string, std::string>::const_iterator it = _data.begin(); it != _data.end(); ++it){
			if (it->first < date)
				prev = it->first;
			else
				break;
		}
		return getVal(prev);
	}
}

bool	BitcoinExchange::getErr()const{return _err;}

void	BitcoinExchange::checkFile(std::string fileName){
	std::ifstream file(fileName.c_str());
	file.seekg(0, std::ios::end); // seekg moves the pointer to the end of the file
	if (file.is_open() == false)
		printErr(NOT_OPEN);
	if (file.tellg() == 0)// check where file pointer position is
		printErr(EMPTY_FIE);
	else
		file.seekg(0, std::ios::beg); // move pointer to begin file
}

std::map<std::string, std::string>	BitcoinExchange::setData(){
	checkFile(DATA);
	std::ifstream file(DATA);
	std::string line;
	std::getline(file, line);
	if (line != "date,exchange_rate")
		printErr(WRONG_FILE);
	size_t del;
	std::string date;
	std::string val;
	std::map<std::string, std::string> res;

	while (std::getline(file, line)){
		del = line.find(',');
		if (del == std::string::npos)
			printErr(BAD_INPUT);
		date = line.substr(0, del);
		if (date.empty() ||  isValidDate(date) == false)
			printErr(INVALID_DATE);
		val = line.substr(del + 1);
		if (!isValidVal(val) )
			printErr(INVALID_VAL);
		if (atof(val.c_str()) < 0)
			printErr(NEG_VAL);
		res.insert(std::make_pair(date, val));
	}
	if (res.size() < 1)
		printErr(EMPTY_FIE);
	file.close();
	return res;
}

void	BitcoinExchange::execBtc(std::string const &fileName){
	checkFile(fileName);
	std::ifstream file(fileName.c_str());
	std::string line;
	
	std::getline(file, line);
	if (line != "date | value")
		throw BitcoinExchange::Err(WRONG_FILE);
	size_t	del;
	std::string	date;
	std::string val;
	std::string	toChang;
	double		res;

	while (std::getline(file, line)){
		del = line.find('|');
		date = line.substr(0, del - 1);
		line[del + 1] ?	val = line.substr(del + 1) : val = "";
		if (isValidDate(date) == false){
			std::cout << INVALID_DATE << " " << line << std::endl;
			continue;
		}
		if (del == std::string::npos || val.empty() || isValidVal(val) == false){
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		if (atof(val.c_str()) > 1000){
			std::cout << "Error: max 1000 btc =>" << line << std::endl;
			continue;
		}
		toChang = getVal(date);
		res = strtod(toChang.c_str(), NULL) * strtod(val.c_str(), NULL);
		if (res < 0)
			std::cout << "Error: not positive number." << std::endl;
		else {
			std::cout << line << " * " << toChang << " = " << std::setprecision(2) << res << std::endl;
		}
	}
	file.close();
}

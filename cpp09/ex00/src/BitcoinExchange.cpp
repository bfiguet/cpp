/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:27:42 by bfiguet           #+#    #+#             */
/*   Updated: 2024/03/22 16:56:05 by bfiguet          ###   ########.fr       */
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

BitcoinExchange::~BitcoinExchange(){};

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

bool	BitcoinExchange::isValidVal(std::string const &val){
	if (isdigit(val.c_str()))
		return true;
	return false;
}

std::map<std::string, std::string>	BitcoinExchange::getData() const{ return _data;}

std::string	BitcoinExchange::getVal(std::string const &date){
	std::map<std::string, std::string>::const_iterator it;

	it = _data.find(date);
	if (it != _data.end())
		return (*it).second;
	else{
		std::string	prevVal = "";
		for (std::map<std::string, std::string>::const_iterator i)
		return prevVal;
	}
}

//static std::string findClosestKey(const std::map<std::string, float>& myMap, const std::string& inputKey) {
//    std::string closestKey = "";
//    for (std::map<std::string, float>::const_iterator it = myMap.begin(); it != myMap.end(); ++it) {
//		if (it->first <= inputKey)
//	    	closestKey = it->first;
//		else
//	    	break;
//    }
//    return closestKey;
//}

//std::string BitcoinExchange::findClosestDate(const std::map<std::string, float>& myMap, const std::string& input) const {

//    std::string closestDate = findClosestKey(myMap, input);

//    if (closestDate.empty())
//		throw TooEarlyDate();
//    return closestDate;
//}

bool	BitcoinExchange::getErr()const{return _err};

std::ifstream	BitcoinExchange::checkFile(std::ifstream file){
	file.seekg(0, std::ios::end); // seekg moves the pointer to the end of the file
	if (file.is_open() == false)
		return printErr(NOT_OPEN);
	if (file.tellg() == 0)// check where file pointer position is
		return printErr(EMPTY_FIE);
	else
		file.seekg(0, std::ios::beg); // move pointer to begin file
	return file;
}

std::map<std::string, std::string>	BitcoinExchange::setData(){
	std::ifstream file = checkFile(DATA);
	std::string line;
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

void	BitcoinExchange::execBtc(std::string const &file){
	std::ifstream file = checkFile(file.c_str());
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
		line[del + 1] ?	val = line.substr(del + 1) : val = NULL;
		if (del == std::string::npos || isValidDate(date) == false
			|| val.empty() || isValidVal(val) == false)
		{
			std::cout << "Error: bad input => " line << std::endl;
			continue;
		}
		toChang = getVal(date);
		res = strtod(toChang.c_str(), NULL) * strtod(val.c_str(), NULL);
		if (final < 0)
			std::cout << "Error: not a positive number." << std::endl;
		else if (res > std::numeric_limits<int>::max())
			std::cout << "Error: too large a number." << std::endl;
		else {
			std::cout << line << " * " << toChang << " = " << round_up(res, 2) << std::endl;
		}
	}
	file.close();
}

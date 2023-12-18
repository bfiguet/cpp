/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:41:12 by bfiguet           #+#    #+#             */
/*   Updated: 2023/12/14 18:11:21 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <iostream>
#include <string>
#include <fstream>

class Replace
{
private:
	std::string	_infile;
	std::string	_outfile;

public:
	Replace(std::string infile);
	~Replace();
	void	run_replace(std::string to_find, std::string to_replace);
	const std::string	getInfile()const;
	const std::string	getOutfile()const;
};

#endif
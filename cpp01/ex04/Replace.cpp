/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:44:53 by bfiguet           #+#    #+#             */
/*   Updated: 2023/12/14 18:29:59 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

Replace::Replace(std::string infile): _infile(infile), _outfile(infile + ".replace")
{
}

Replace::~Replace()
{
}

void	Replace::run_replace(std::string to_find, std::string to_replace)
{
	std::string		buf;
	size_t			i;
	std::ifstream	file(this->_infile.c_str());

	if (file.is_open())
	{
		if (std::getline(file, buf, '\0'))
		{
			std::ofstream	ofs(this->_outfile.c_str());//cpy
			i = buf.find(to_find);//return start posix
			while (i != std::string::npos)
			//const statique size_t npos = -1 ;
			{
				buf.erase(i, to_find.length());
				buf.insert(i, to_replace);
				i = buf.find(to_find, i + to_replace.length());
				//i == -1;
			}
			ofs << buf;
			ofs.close();
		}
		file.close();
	}
	else
		std::cerr << "Error to open: " << this->_infile << std::endl;
}

const std::string	Replace::getInfile()const
{
	return this->_infile;
}

const std::string Replace::getOutfile()const
{
	return this->_outfile;
}

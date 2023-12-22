/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 12:13:53 by bfiguet           #+#    #+#             */
/*   Updated: 2023/12/22 00:05:31 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain
{
public:
	Brain();
	Brain(Brain const & rhs);
	virtual ~Brain();
	Brain & operator=(const Brain  & rhs);
	std::string const getIdea(int i)const;
	void	setIdea(int i, std::string const idea);

private:
	std::string _ideas[100];
};

#endif
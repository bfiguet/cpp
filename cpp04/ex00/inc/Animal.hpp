/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 11:58:24 by bfiguet           #+#    #+#             */
/*   Updated: 2023/12/21 19:07:41 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{
protected:
	std::string _type;
public:
	Animal();
	Animal(std::string const & type);
	Animal(Animal const & rhs);
	virtual ~Animal();
	Animal & operator=(const Animal  & rhs);

	std::string	const &	getType()const;
	virtual void		makeSound()const;
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 18:38:41 by bfiguet           #+#    #+#             */
/*   Updated: 2023/12/21 19:07:51 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

class WrongAnimal
{
protected:
	std::string _type;
public:
	WrongAnimal();
	WrongAnimal(std::string const & type);
	WrongAnimal(WrongAnimal const & rhs);
	virtual ~WrongAnimal();

	WrongAnimal & operator=(WrongAnimal const & rhs);
	std::string const & getType()const;
	void	makeSound()const;
};


#endif
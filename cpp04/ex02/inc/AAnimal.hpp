/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 11:58:24 by bfiguet           #+#    #+#             */
/*   Updated: 2023/12/22 01:04:35 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include <string>

class AAnimal
{

public:
	AAnimal();
	AAnimal(AAnimal const & rhs);
	virtual ~AAnimal();
	AAnimal & operator=(const AAnimal  & rhs);
	std::string	const &	getType()const;
	virtual void		makeSound()const = 0;

protected:
	std::string _type;
};

#endif
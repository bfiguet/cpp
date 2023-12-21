/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 18:29:43 by bfiguet           #+#    #+#             */
/*   Updated: 2023/12/21 19:07:48 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include"Animal.hpp"

class Dog : public Animal
{
public:
	Dog();
	Dog(Dog const & rhs);
	~Dog();

	Dog & operator=(const Dog & rhs);
	void	makeSound()const;
	
};

#endif
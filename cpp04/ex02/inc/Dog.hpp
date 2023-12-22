/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 18:29:43 by bfiguet           #+#    #+#             */
/*   Updated: 2023/12/22 00:51:38 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include"AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal
{
public:
	Dog();
	Dog(Dog const & rhs);
	~Dog();

	Dog & operator=(const Dog & rhs);
	void	makeSound()const;
	void	setIdea(int i, std::string idea)const;
	void	showIdea()const;
private:
	Brain*	_brain;	
};

#endif
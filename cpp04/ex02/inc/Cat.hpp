/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 18:19:48 by bfiguet           #+#    #+#             */
/*   Updated: 2023/12/22 00:51:05 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal
{
public:
	Cat();
	Cat(Cat const & rhs);
	~Cat();

	Cat & operator=(const Cat  & rhs);
	void	makeSound()const;
	void	setIdea(int i, std::string idea)const;
	void	showIdea()const;
private:
	Brain*	_brain;
};

#endif
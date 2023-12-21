/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 11:50:38 by bfiguet           #+#    #+#             */
/*   Updated: 2023/12/21 15:44:20 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	ScavTrap();
	ScavTrap(std:: string name);
	ScavTrap(const ScavTrap & rhs);
	~ScavTrap();

	ScavTrap & operator=(const ScavTrap & rhs);
	void	attack(const std::string & target);
	void	guardGate();
};

#endif

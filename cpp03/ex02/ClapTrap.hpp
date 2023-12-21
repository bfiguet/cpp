/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 18:30:22 by bfiguet           #+#    #+#             */
/*   Updated: 2023/12/21 16:02:22 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap( const ClapTrap& rhs );
	~ClapTrap();

	ClapTrap &		operator=(ClapTrap const & rhs);	

	void			attack(const std::string & target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);
	//unsigned int	getHitPoint()const;

protected:
	std::string		_name;
	unsigned int	_hitPoints;
	unsigned int	_energyPoints;
	unsigned int	_attackDamage;

};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 18:30:22 by bfiguet           #+#    #+#             */
/*   Updated: 2023/12/20 20:11:17 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
public:
	ClapTrap(std::string name);
	ClapTrap( const ClapTrap& rhs );
	~ClapTrap();

	ClapTrap &		operator=(ClapTrap const & rhs);	

	void			attack(const std::string & target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);

private:
	ClapTrap();
	std::string		_name;
	unsigned int	_hitPoints;
	unsigned int	_energyPoints;
	unsigned int	_attackDamage;

};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:00:38 by bfiguet           #+#    #+#             */
/*   Updated: 2023/12/19 11:36:56 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAMPLE_HPP
#define SAMPLE_HPP

#include <iostream>
#include <string>

//CLASSE CANONIQUE:
//	constructeur par defaut
//	constructeur par copie
//	operator d'assignation
//	et destructeur virtuel

class Sample
{
public:
	Sample();//constructeur par defaut
	Sample(int const n); // Parametric Constructor // Forme canonique
	Sample(Sample const & src); //constructeur par copie  // Forme canonique
	~Sample(); //Destructeur virtuel pas encore le cas ici //Forme canonique

	Sample & operator=(Sample const & rhs); //Operateur d'assignation //Forme canonique
	int getFoo()const;
	//surcharge d'operateur?
	void bar(char const c) const;
	void bar(int const n) const;
	void bar(float const z) const;
	void bar(Sample const & i) const;

private:
	int	_foo;
};

std::ostream & operator<<(std::ostream & o, Sample const & i);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 17:01:16 by bfiguet           #+#    #+#             */
/*   Updated: 2024/03/17 17:29:48 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

# include <cstdlib>
# include <iostream>

class Base
{
public:
	virtual ~Base();
};

class A : public Base {};

class B : public Base {};

class C : public Base {};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 17:01:16 by bfiguet           #+#    #+#             */
/*   Updated: 2024/03/18 12:45:16 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

# include <cstdlib>
# include <iostream>
# include  <typeinfo>

class Base
{
public:
	virtual ~Base(){};
};

class A : public Base {
	public:
	A(){std::cout << "Constructor Base A" << std::endl;};
	~A(){std::cout << "Destructor Base A" << std::endl;};
};

class B : public Base {
	public:
	B(){std::cout << "Constructor Base B" << std::endl;};
	~B(){std::cout << "Destructor Base B" << std::endl;};
};

class C : public Base {
	public:
	C(){std::cout << "Constructor Base C" << std::endl;};
	~C(){std::cout << "Destructor Base C" << std::endl;};	
};

#endif
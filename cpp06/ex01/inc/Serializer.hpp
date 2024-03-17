/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:16:19 by bfiguet           #+#    #+#             */
/*   Updated: 2024/03/17 16:59:05 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <string>
#include <iostream>
#include <stdint.h>

typedef struct Data{
	int	val;
}	Data;

class Serializer
{
private:
	Serializer();
	Serializer(const Serializer &cpy){*this = cpy;};
	~Serializer();

	Serializer	&operator=(const Serializer &src){(void)src; return *this;};

public:
	static uintptr_t	serialize(Data* ptr);
	static Data*		deserialize(uintptr_t raw);
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:17:15 by bfiguet           #+#    #+#             */
/*   Updated: 2024/03/20 11:29:58 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(){};
Serializer::Serializer(const Serializer &cpy){*this = cpy;};
Serializer::~Serializer(){};

Serializer & Serializer::operator=(const Serializer &src){(void)src; return *this;};


uintptr_t	Serializer::serialize(Data* ptr){
	return reinterpret_cast<uintptr_t>(ptr);
}

Data*	Serializer::deserialize(uintptr_t raw){
	return reinterpret_cast<Data*>(raw);
}

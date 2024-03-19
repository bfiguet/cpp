/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 17:46:15 by bfiguet           #+#    #+#             */
/*   Updated: 2024/03/19 15:39:54 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>
#include <string>

template<typename T>

void	swap(T &s1, T &s2){
	T s3;
	s3 = s1;
	s1 = s2;
	s2 = s3;
}

template< typename T>

T	min(T m1, T m2){
	return m1 < m2 ? m1 : m2;
}

template<typename T>

T	max(T ma1, T ma2){
	return ma1 > ma2 ? ma1 : ma2;
}

#endif

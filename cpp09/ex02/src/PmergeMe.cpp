
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:47:19 by bfiguet           #+#    #+#             */
/*   Updated: 2024/03/27 12:49:16 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}
PmergeMe::PmergeMe(const PmergeMe& src) { (void)src; }
PmergeMe& PmergeMe::operator=(const PmergeMe& src) { (void)src; return (*this); }
PmergeMe::~PmergeMe(){}
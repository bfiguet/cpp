/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 19:52:56 by bfiguet           #+#    #+#             */
/*   Updated: 2024/05/27 21:20:42 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_TPP
#define PMERGEME_TPP

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

template<typename T>
static void	parse(T& container, const std::string& str)
{
	std::istringstream iss(str);
	std::ostringstream oss;
	unsigned int n;

	for (std::string::size_type i = 0; i < str.size(); i++)
		if(!isdigit(str[i]) && str[i] != ' ')
			throw std::runtime_error(oss.str());

	while (iss >> n)
		container.push_back(n);
	if (iss.fail() && !iss.eof())
		throw std::invalid_argument("Invalid argument");
}

template<typename T>
static T merge(T& a, T& b)
{
	T	c;
	typename T::size_type i = 0;
	typename T::size_type j = 0;

	while (i < a.size() && j < b.size())
	{
		if (a[i] < b[j])
			c.push_back(a[i++]);
		else
			c.push_back(b[j++]);
	}
	while (i < a.size())
		c.push_back(a[i++]);
	while (j < b.size())
		c.push_back(b[j++]);
	return c;
}

template<typename T>
static T mergeSort(T container)
{
	if (container.size() < 2)
		return container;
	if (container.size() == 2 && container[0] > container[1])
		return (std::swap(container[0], container[1]), container);
	
	T a = mergeSort(T(container.begin(), container.begin() + container.size() / 2));
	T b = mergeSort(T(container.begin() + container.size() / 2, container.end()));

	return merge(a, b);
}

template<typename T>
static void sortPair(T& container)
{
	for (typename T::size_type i = 0; i < container.size() - 1; i += 2)
		if (container[i] > container[i + 1])
			std::swap(container[i], container[i + 1]);
}

template<typename T>
static void sortInsert(T& container, T& buff)
{
	int		low;
	int		high;
	int		mid;

	for (typename T::size_type i = 0; i < buff.size(); ++i)
	{
		low = 0;
		high = container.size() - 1;
		while (low <= high)
		{
			mid = (low + high) / 2;
			if (buff[i] < container[mid])
				high = mid - 1;
			else
				low = mid + 1;
		}
		container.insert(container.begin() + low, buff[i]);
	}
}

template<typename T>
void PmergeMe::sort(T& container, const std::string& str)
{
	T	start;
	T	buff;

	parse(container, str);
	if (container.size() < 2)
		return;
	
	sortPair(container);

	for (typename T::size_type i = 0; i < container.size() - 1; i += 2)
		start.push_back(container[i + 1]);
	for (typename T::size_type i = 0; i < container.size(); i += 2)
		buff.push_back(container[i]);

	container = mergeSort(start);
	sortInsert(container, buff);
}

#endif
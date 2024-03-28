/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:47:19 by bfiguet           #+#    #+#             */
/*   Updated: 2024/03/28 16:31:58 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_CPP
#define PMERGEME_CPP

#include "PmergeMe.hpp"

template <template <typename, typename> class Container>
void	PmergeMe<Container>::printRes(void)const{
	for(size_t i = 0; i < _after.size() ; i++)
		std::cout << _after[i] << " ";
	std::cout << std::endl;
}

template <template <typename, typename> class Container>
PmergeMe<Container>::PmergeMe(char **av): _size(0)
{
	for (size_t i = 1; av[i]; i++)
	{
		if (std::string(av[i]).find_first_not_of("0123456789 ") != std::string::npos)
			throw PmergeMe::Err("Invalid Arguments");
		else
		{
			if (av[0])
				std::cout << "Before ";
			_before.push_back(atoi(av[i]));
			std::cout << _before[i] << " ";
			_size++;
		}
	}
}

template <template <typename, typename> class Container>
static Container<int, std::allocator<int> >	mergeEnd(Container<int, std::allocator<int> > &one, Container<int, std::allocator<int> > &two){
	Container<int, std::allocator<int> >	res;
	while (!one.empty() && !two.empty()){
		if(one.front() <= two.front()){
			res.push_back(one.front());
			one.erase(one.begin());
		}
		else{
			res.push_back(two.front());
			two.erase(two.begin());
		}
	}
	while (!one.empty()){
		res.push_back(one.front());
		one.erase(one.begin());
	}
	while (!two.empty()){
		res.push_back(two.front());
		two.erase(two.begin());
	}
	return res;
}

template <template <typename, typename> class Container>
static Container<int, std::allocator<int> >	mergeInsert(Container<int, std::allocator<int> > &tab){
	if (tab.size() <= 1)
		return tab;
	int middle = tab.size() / 2;
	Container<int, std::allocator<int> > one(tab.begin(), tab.begin() + middle);
	Container<int, std::allocator<int> > two(tab.begin() + middle, tab.end());
	one = mergeInsert(one);
	two = mergeInsert(two);
	return mergeEnd(one, two);
}

template <template <typename, typename> class Container>
void	PmergeMe<Container>::sort(){
	std::clock_t	start = std::clock();

	_after = mergeInsert(_before);
	double end = static_cast<double>(std::clock() - start) / CLOCKS_PER_SEC; 
	std::cout << "After: ";
	printRes();

	std::cout << "Time to process a range of " << _size << " elements " << "with std::vector<unsigned int> : "
		<< end << " us" << std::endl;
}

#endif

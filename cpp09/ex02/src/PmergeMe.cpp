
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

static void	printRes(std::vector<int> &tab){
	std::vector<int>::const_iterator it;
	for(it = tab.begin(); it != tab.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

PmergeMe::PmergeMe(int ac, char **av): _size(ac - 1){
	for (int i = 1; i <= _size; i++)
	{
		if (std::string(av[i]).find_first_not_of("0123456789 ") != std::string::npos)
			throw PmergeMe::Err("Invalid Arguments");
		if (i == 1)
			std::cout << "Before ";
		_before.push_back(atoi(av[i]));
		std::cout << atoi(av[i]) << " ";
	}
	std::cout << std::endl;
}

PmergeMe::~PmergeMe(){}

static std::vector<int>	mergeVectorEnd(std::vector<int> &one, std::vector<int> &two){
	std::vector<int>	res;
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

static std::vector<int>	mergeInsertVector(std::vector<int> &tab){
	if (tab.size() <= 1)
		return tab;
	int middle = tab.size() / 2;
	std::vector<int> one(tab.begin(), tab.begin() + middle);
	std::vector<int> two(tab.begin() + middle, tab.end());
	one = mergeInsertVector(one);
	two = mergeInsertVector(two);
	return mergeVectorEnd(one, two);
}

void	PmergeMe::vectorMethod(){
	std::vector<int>	res;
	std::clock_t	start = std::clock();

	res = mergeInsertVector(_before);
	double end = static_cast<double>(std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC) * 100000; 
	std::cout << "After: ";
	printRes(res);

	std::cout << "Time to process a range of " << _size << " elements " << "with std::vector<int> : "
		<< end << " us" << std::endl;
}

static std::list<int>	mergeListEnd(std::list<int> &one, std::list<int> &two){
	std::list<int>	res;
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

static std::list<int>	mergeInsertList(std::list<int> lst){
	if (lst.size() <= 1)
		return lst;
	int middle = lst.size() / 2;
	std::list<int> one;
	std::list<int> two;
	for (int i = 0; i < middle; i++){
		one.push_back(lst.front());
		lst.pop_front();
	}
	two = lst;

	one = mergeInsertList(one);
	two = mergeInsertList(two);
	return mergeListEnd(one, two);
}

void	PmergeMe::listMethod(char **av){
	std::list<int>	lst;
	for(int i = 0; i < _size ; i++)
		lst.push_back(atoi(av[i]));
	
	std::clock_t	start = std::clock();
	lst = mergeInsertList(lst);
	double	end = static_cast<double>(std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC) * 100000;

	std::cout << "Time to process a range of " << _size << " elements " << "with std::list<int> : "
		<< end << " us" << std::endl;
}

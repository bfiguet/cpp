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

PmergeMe::PmergeMe(int ac, char **av){
	for (int i = 1; i < ac; i++)
		if (std::string(av[i]).find_first_not_of("0123456789 ") != std::string::npos)
			throw PmergeMe::Err("Invalid Arguments");
	
	std::vector<unsigned int>	tab;
	for(int i = 1; i < ac; i++)
		tab.push_back(ft_iss(av[i]));
	std::cout << "Before ";
	ft_print(tab);
	_tab = tab;
}

PmergeMe::~PmergeMe(){}

static void	ft_print(std::vector<unsigned int> &tab){
	std::vector<unsigned int>::const_iterator it;
	for(it = tab.begin(); it != tab.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

static std::vector<unsigned int>	mergeEnd(std::vector<unsigned int> &one, std::vector<unsigned int> &two){
	std::vector<unsigned int>	res;
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
		res.push_back(two.begin());
		two.erase(two.begin());
	}
	return res;
}

static std::vector<unsigned int>	mergeInsertVector(std::vector<unsigned int> &tab){
	if (tab.size() <= 1)
		return tab;
	int middle = tab.size() / 2;
	std::vector<unsigned int> one(tab.begin(), tab.begin() + middle);
	std::vector<unsigned int> two(tab.begin() + middle, tab.end());
	one = mergeInsertVector(one);
	two = mergeInsertVector(two);
	return mergeEnd(one, two);
}

void	PmergeMe::vectorMethod(){
	std::vector<unsigned int>	res;
	std::clock_t	start = std::clock();

	res = mergeInsertVector(_tab);
	double end = static_cast<double>(std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC) * 100000; 
	std::cout << "After: ";
	ft_print(res);
}

static void	mergeInsertList(std::list list){
//ICI
}

void	PmergeMe::listMethod(int ac, char **av){
	std::list<unsigned int>	list;
	for(int i = 1; i < ac ; i++)
		list.push_back(ft_iss(av[i]));
	
	std::clock_t	start = std::clock();
	mergeInsertList(list);
	double	end = static_cast<double>(std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC) * 100000;

	std::cout << "Time to process a range of " << ac - 1 << " elements " << "with std::list<unsigned int> : "
		<< end << " us" << std::endl;
}

unsigned int	ft_iss(std::string const &str){
	std::istringstream iss(str);
	unsigned int n;
	iss >> n;
	return n;
}

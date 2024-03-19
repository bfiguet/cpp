/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pair.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 12:05:47 by bfiguet           #+#    #+#             */
/*   Updated: 2024/03/19 12:41:54 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

template< typename T, typename U>
class Pair{
public:
	Pair<T, U>(T const & lhs, U const & rhs): _lhs(lhs), _rhs(rhs){
		std::cout << "Generic template" << std::endl;
		return ;
	}
	~Pair<T, U>(void){}

	T const & fst(void)const {return this->_lhs;}
	U const & snd(void)const {return this->_rhs;}

private:
	T const &	_lhs;
	U const &	_rhs;
	Pair<T, U>(void);
};

//SPECIALIZATION PARTIAL
template<typename U>
class Pair<int, U>{
public:
	Pair<int, U>(int lhs, U const & rhs): _lhs(lhs), _rhs(rhs){
		std::cout << "Int partial specialization" << std::endl;
		return ;
	}
	~Pair<int, U>(void){}

	int	fst(void)const {return this->_lhs;}
	U const & snd(void)const {return this->_rhs;}

private:
	int			_lhs;
	U const &	_rhs;
	Pair<int, U>(void);
};

//SPECIALIZATION BOOL
template<>
class Pair<bool, bool>{
public:
	Pair<bool, bool>(bool lhs, bool rhs){
		std::cout << "Bool specialization" << std::endl;
		this->_n = 0; //init
		this->_n |= static_cast<int>(lhs) << 0; // ou = decalage 0 bite pr avoir le 0
		this->_n |= static_cast<int>(rhs) << 1; // ou= decalage 1 bite pour avoir le 1
		return ;
	}
	~Pair<bool, bool>(void){}

	bool	fst(void)const {return this->_n & 0x01;}
	bool	snd(void)const {return this->_n & 0x02;}

private:
	int			_n;
	Pair<bool, bool>(void);
};


template<typename T, typename U>
std::ostream & operator<<(std::ostream & o, Pair<T, U> const & p){
	o<< "Pair( " << p.fst() << ", " << p.snd() << " )";
	return o;
}

std::ostream & operator<<(std::ostream & o, Pair<bool, bool> const & p){
	o<< std::boolalpha << "Pair( " << p.fst() << ", " << p.snd() << " )";
	return o;
}

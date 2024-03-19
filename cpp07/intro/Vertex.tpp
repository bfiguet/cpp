/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vertex.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:15:46 by bfiguet           #+#    #+#             */
/*   Updated: 2024/03/19 11:53:49 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

template< typename T = float> //default type
class Vertex{
public:
	Vertex(T const & x, T const & y, T const & z): _x(x), _y(y), _z(z){}
	~Vertex(void){}

	T const & getX(void)const{return this->_x;}
	T const & getY(void)const{return this->_y;}
	T const & getZ(void)const{return this->_z;}

	//etc...

private:
	T const	_x;
	T const	_y;
	T const	_z;
	Vertex(void);
};

template< typename T>
std::ostream & operator<<(std::ostream & o, Vertex<T> const & v){
	std::cout.precision(1);
	o << setiosflags(std::ios::fixed);
	o << "Vertex( ";
	o << v.getX() << ", ";
	o << v.getY() << ", ";
	o << v.getZ();
	o << " )";
	return o;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:43:11 by bfiguet           #+#    #+#             */
/*   Updated: 2024/03/19 12:33:03 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

///////TEMPLATE FUNCTION//////////
#include <iostream>

//template<typename T> //Template definition
//exampl template<typename T, typename U> -> List<int, float>
//stl ->Standard Template Librery

//TEMPLATE FUNC MAX
//T max (T const & x, T const & y){//T designs any type but always same
//	return (x >= y ? x : y);
//}

//int	foo(int x){
//	std::cout <<"Long computing time"<<std::endl;
//	return x;
//}

//int main(){
//	int	a = 21;
//	int	b = 42;
//	std::cout << "max of "<< a << " and "<< b << " is " << max<int>(a,b) <<std::endl; //Explicit instanciation
//	std::cout << "max of "<< a << " and "<< b << " is " << max(a,b) <<std::endl; // Implicit

//	float	c = 1.7f;
//	float	d = 4.2f;
//	std::cout << "max of "<< c << " and "<< d << " is " << max<float>(c,d) <<std::endl;
//	std::cout << "max of "<< c << " and "<< d << " is " << max(c,d) <<std::endl;

//	char	e = 'e';
//	char	f = 'F';
//	std::cout << "max of "<< e << " and "<< f << " is " << max<char>(e,f) <<std::endl;
//	std::cout << "max of "<< e << " and "<< f << " is " << max(e,f) <<std::endl;

//	int ret = max<int>(foo(a), foo(b)); //Explicit
//	std::cout << "max of "<< a << " and "<< b << " is " << ret <<std::endl;
//}

//class List //Template of class no simpl class
//{
//public:
//	List<T>(T const & content){};
//	List<T>(List<T> const & list){};
//	~List<T>(){};

//private:
//	T *			_content;
//	List<T>*	_next;
//};

//int main(){
//	List<int>		a(42);
//	List<float>		b(3.14f);
//	List<List<int>>	c(a);

//	return 0;
//}

//------------------------------------------------------------
//#include "Vertex.tpp"

//int main(void){
//	Vertex<int>	v1(12, 23, 34);
//	Vertex<>	v2(12, 23, 34);

//	std::cout << v1 << std::endl;
//	std::cout << v2 << std::endl;
//	return 0;
//}

// g++ -Wall -Wextra -Werror -Wno-unused main.cpp && ./a.out

//----------------------------------------------------------------

#include "Pair.tpp"

int main(void){
	Pair< int, int>				p1(4, 2);
	Pair<std::string, float>	p2(std::string("Pi"), 3.14f);
	Pair<float, bool>			p3(4.2f, true);
	Pair<bool, bool>			p4(true, false);

	std::cout << p1 << std::endl;
	std::cout << p2 << std::endl;
	std::cout << p3 << std::endl;
	std::cout << p4 << std::endl;
	return 0;
}
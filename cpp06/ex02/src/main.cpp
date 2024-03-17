/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 17:07:53 by bfiguet           #+#    #+#             */
/*   Updated: 2024/03/17 17:41:13 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base(){}

Base*	generate(void){
	 if (std::rand() % 3 == 0)
		return new A;
	else if (std::rand() % 3 == 1)
		return new B;
	else
		return new C;
}

void	identify(Base* p){
	try{
		if (dynamic_cast<A*>(p))
			std::cout << "Actual type A*" << std::endl;
		else if (dynamic_cast<B*>(p))
			std::cout << "Actual type B*" << std::endl;
		else if (dynamic_cast<C*>(p))
			std::cout << "Actual type C*" << std::endl;
	}catch (const std::exception &e){
		std::cerr << "Base* p ERR " << e.what() <<std::endl;
	}
}

void	identify(Base& p){
	try{
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A& OK" << std::endl;
	}catch (const std::exception& e){
		std::cerr << "A& ERR " << e.what() << std::endl;
	}
	try
	{
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B& OK" << std::endl;
	}catch(const std::exception& e){
		std::cerr << "B& ERR " << e.what() << std::endl;;
	}
	try
	{
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C& OK" << std::endl;
	}catch(const std::exception& e){
		std::cerr << "C& ERR " << e.what() << std::endl;;
	}
}

int	main(){
	Base *base1 = generate();
	Base *base2 = generate();
	Base *base3 = generate();
	Base *base4 = generate();
	identify(base1);
	identify(*base1);
	identify(base2);
	identify(*base2);
	identify(base3);
	identify(*base3);
	identify(base4);
	identify(*base4);
	delete base1;
	delete base2;
	delete base3;
	delete base4;
	return 0;
}

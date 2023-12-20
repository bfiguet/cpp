/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:08:40 by bfiguet           #+#    #+#             */
/*   Updated: 2023/12/19 11:44:50 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sample.hpp"
#include "Integer.hpp"

int	main()
{
	//
	//Sample instance;
	//instance.bar('a');
	//instance.bar(42);
	//instance.bar(3.14f);
	//instance.bar(instance);

	//Integer x(30);
	//Integer y(10);
	//Integer z(0);

	//std::cout << "Value of x: " << x << std::endl;
	//std::cout << "Value of y: " << y << std::endl;
	//y = Integer(12);
	//std::cout << "Value of y: " << y << std::endl;
	//std::cout << "Value of z: " << z << std::endl;
	//z = x + y;
	//std::cout << "Value of z: " << z << std::endl;

	Sample	instance1;
	Sample	instance2(42);
	Sample	instance3(instance1);

	std::cout << instance1 << std::endl;
	std::cout << instance2 << std::endl;
	std::cout << instance3 << std::endl;

	instance3 = instance2;
	std::cout << instance3 << std::endl;

	return 0;
}
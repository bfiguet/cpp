/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:08:40 by bfiguet           #+#    #+#             */
/*   Updated: 2023/12/18 13:12:28 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sample.hpp"

int	main()
{
	Sample instance;
	instance.bar('a');
	instance.bar(42);
	instance.bar(3.14);
	instance.bar(instance);
}
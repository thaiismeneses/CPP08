/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 17:34:46 by thfranco          #+#    #+#             */
/*   Updated: 2025/06/28 18:30:15 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int	main()
{
	// Test with std::vector
	std::vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);

	std::cout << "Testing with std::vector" << std::endl;
	try
	{
		std::vector<int>::const_iterator it = easyfind(vec, 20);
		std::cout << "Found value: " << *it << std::endl;

		it = easyfind(vec, 40); // This will throw an exception
	}
	catch(const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl;

	// Test with std::list
	std::list<int> lst;
	lst.push_back(3);
	lst.push_back(6);
	lst.push_back(9);

	std::cout << "Testing with std::list" << std::endl;
	try
	{
		std::list<int>::const_iterator it = easyfind(lst, 6);
		std::cout << "Found value: " << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	return 0;
}

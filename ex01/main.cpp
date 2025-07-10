/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 18:34:03 by thfranco          #+#    #+#             */
/*   Updated: 2025/07/09 22:49:30 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdlib.h>      // to rand()
#include <time.h>        // to time()
#include <vector>
#include <list>
#include <algorithm>
#include "Span.hpp"

int main()
{
	// Test 1: Using basic
	std::cout << "== Basic Test ==" << std::endl;
	try {
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n== Limit Test ==" << std::endl;
	try {
		Span sp = Span(2);
		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(3); // should throw an exception
	} catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n== Test of span with less than two elements ==" << std::endl;
	try {
		Span sp = Span(1);
		sp.addNumber(42);
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl; // deve lançar exceção
	} catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n== Test with vector iterators ==" << std::endl;
	try {
		Span sp = Span(5);
		std::vector<int> numbers;
		numbers.push_back(2);
		numbers.push_back(4);
		numbers.push_back(6);
		numbers.push_back(8);
		numbers.push_back(10);

		sp.addNumbers(numbers.begin(), numbers.end());
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n== Test with list iterators ==" << std::endl;
	try {
		Span sp = Span(4);
		std::list<int> numbers;
		numbers.push_back(3);
		numbers.push_back(9);
		numbers.push_back(27);
		numbers.push_back(81);

		sp.addNumbers(numbers.begin(), numbers.end());
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n== Test with 10.000 rand numbers using iterators ==" << std::endl;
	try {
		Span sp = Span(10000);
		std::vector<int> numbers(10000);

		srand(time(NULL));
		std::generate(numbers.begin(), numbers.end(), rand);
		sp.addNumbers(numbers.begin(), numbers.end());

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	return 0;
}


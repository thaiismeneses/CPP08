/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 18:34:03 by thfranco          #+#    #+#             */
/*   Updated: 2025/06/28 19:31:04 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#include <iostream>
#include <cstdlib>      // para rand()
#include <ctime>        // para time()
#include "Span.hpp"

int main()
{
	// Teste 1: uso básico
	std::cout << "== Teste básico ==" << std::endl;
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
		std::cout << "Erro: " << e.what() << std::endl;
	}

	std::cout << "\n== Teste de limite ==" << std::endl;
	try {
		Span sp = Span(2);
		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(3); // deve lançar exceção
	} catch (std::exception &e) {
		std::cout << "Erro: " << e.what() << std::endl;
	}

	std::cout << "\n== Teste de span com menos de dois elementos ==" << std::endl;
	try {
		Span sp = Span(1);
		sp.addNumber(42);
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl; // deve lançar exceção
	} catch (std::exception &e) {
		std::cout << "Erro: " << e.what() << std::endl;
	}

	std::cout << "\n== Teste com 10.000 números aleatórios ==" << std::endl;
	try {
		Span sp = Span(10000);
		srand(time(NULL)); // inicializa aleatoriedade

		for (int i = 0; i < 10000; ++i)
			sp.addNumber(rand());

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << "Erro: " << e.what() << std::endl;
	}

	return 0;
}


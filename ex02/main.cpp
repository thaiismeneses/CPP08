/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 14:55:26 by thfranco          #+#    #+#             */
/*   Updated: 2025/06/30 17:05:41 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>

int main()
{
	// Cria uma MutantStack de int
	MutantStack<int> mstack;

	std::cout << "== Testando push e top ==" << std::endl;
	mstack.push(5);
	mstack.push(17);

	std::cout << "Topo: " << mstack.top() << std::endl;

	std::cout << "== Testando pop ==" << std::endl;
	mstack.pop();
	std::cout << "Tamanho após pop: " << mstack.size() << std::endl;

	std::cout << "== Adicionando mais elementos ==" << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	std::cout << "== Iterando pela pilha ==" << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	for (; it != ite; ++it)
		std::cout << *it << std::endl;

	std::cout << "== Testando cópia em stack padrão ==" << std::endl;
	std::stack<int> s(mstack);

	std::cout << "Topo da cópia (std::stack): " << s.top() << std::endl;

	return 0;
}



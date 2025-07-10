/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 14:55:26 by thfranco          #+#    #+#             */
/*   Updated: 2025/07/09 22:54:46 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>

int main()
{
	// Creates a MutantStack of int
	MutantStack<int> mstack;

	std::cout << "== Testing push and top ==" << std::endl;
	mstack.push(5);
	mstack.push(17);

	std::cout << "Top: " << mstack.top() << std::endl;

	std::cout << "== Testing pop ==" << std::endl;
	mstack.pop();
	std::cout << "Size after pop: " << mstack.size() << std::endl;

	std::cout << "== Adding more elements ==" << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	std::cout << "== Iterating through the stack ==" << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	for (; it != ite; ++it)
		std::cout << *it << std::endl;

	std::cout << "== Testing copy to standard stack ==" << std::endl;
	std::stack<int> s(mstack);

	std::cout << "Top of copy (std::stack): " << s.top() << std::endl;

	return 0;
}



/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:26:26 by thfranco          #+#    #+#             */
/*   Updated: 2025/06/30 17:04:20 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &other) : std::stack<T>(other) {}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &other)
{
	if (this != &other)
		std::stack<T>::operator=(other);
	return this;
}

template <typename T>
MutantStack<T>::~MutantStack(){}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return this->c.begin();
}
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return this->c.end();
}

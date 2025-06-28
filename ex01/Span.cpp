/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 18:34:07 by thfranco          #+#    #+#             */
/*   Updated: 2025/06/28 19:29:33 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(): _Max(0) {};

Span::Span(unsigned int N): _Max(N) {};

Span::Span(const Span &other):_Numbers(other._Numbers), _Max(other._Max) {};

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		this->_Numbers = other._Numbers;
		this->_Max = other._Max;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int number)
{
	if (_Numbers.size() >= _Max)
		throw std::runtime_error("Cannot add number: Span is full");
	_Numbers.push_back(number);
}
int Span::shortestSpan() const
{
	if (_Numbers.size() < 2)
		throw std::runtime_error("Cannot find shortest span: not enough numbers");
	std::vector<int>sorted = _Numbers;
	std::sort(sorted.begin(), sorted.end());

	int minSpan = std::abs(sorted[1] - sorted[0]);
	for (size_t i = 1; i < sorted.size() - 1 ; ++i)
	{
		int diff = std::abs(sorted[i + 1] - sorted[i]);
		if (diff < minSpan)
			minSpan = diff;
	}
	return minSpan;
}

int Span::longestSpan() const
{
	if (_Numbers.size() < 2)
		throw std::runtime_error("Cannot find longest span: not enough numbers");

	int minValue = *std::min_element(_Numbers.begin(), _Numbers.end());
	int maxValue = *std::max_element(_Numbers.begin(), _Numbers.end());

	return maxValue - minValue;
}

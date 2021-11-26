/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 01:23:42 by sikeda            #+#    #+#             */
/*   Updated: 2021/11/26 22:55:51 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include "span.hpp"

/* ************************************************************************** */
/*   orthodox canonical form                                                  */
/* ************************************************************************** */

Span::Span(unsigned n)
	: _max(n)
{}

Span::Span(const Span& other)
{
	*this = other;
}

Span&	Span::operator=(const Span& other)
{
	if (this != &other)
	{
		_max = other._max;
		_vector = other._vector;
	}
	return *this;
}

Span::~Span()
{}

/* ************************************************************************** */
/*   methods                                                                  */
/* ************************************************************************** */

void	Span::addNumber(int n)
{
	if (_vector.size() < _max)
		_vector.push_back(n);
	else
		throw std::out_of_range("out of range");
}

unsigned	Span::shortestSpan() const
{
	if (_vector.size() < 2)
		throw std::logic_error("no span to find");

	std::vector<int> sorted = _vector;
	sort(sorted.begin(), sorted.end());
	unsigned shortest_span = std::numeric_limits<unsigned>::max();
	for (std::vector<int>::const_iterator p = sorted.begin(); p != sorted.end(); ++p)
	{
		if (p + 1 != sorted.end())
			if (static_cast<unsigned>(*(p + 1) - *p) < shortest_span)
				shortest_span = static_cast<unsigned>(*(p + 1) - *p);
	}
	return shortest_span;
}

unsigned	Span::longestSpan() const
{
	if (_vector.size() < 2)
		throw std::logic_error("no span to find");

	std::vector<int> copy = _vector;
	std::vector<int>::iterator min = std::min_element(copy.begin(), copy.end());
	std::vector<int>::iterator max = std::max_element(copy.begin(), copy.end());
	return *max - *min;
}

void	Span::addNumbers(int start, unsigned n, int jump)
{
	if (_max < n)
		throw std::out_of_range("out of range");

	int num = start;
	for (unsigned i = 0; i < n; i++)
	{
		_vector.push_back(num);
		num += jump;
	}
}

void	Span::print_vector_int() const
{
	std::cout << "{ ";
	for (std::vector<int>::size_type i = 0; i != _vector.size(); ++i)
		std::cout << _vector[i] << ' ';
	std::cout << '}' << std::endl;
}

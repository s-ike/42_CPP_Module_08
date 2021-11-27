/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 01:22:32 by sikeda            #+#    #+#             */
/*   Updated: 2021/11/27 18:48:04 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>

class Span
{
	unsigned			_max;
	std::vector<int>	_vector;

	// orthodox canonical form
	Span();

public:
	// orthodox canonical form
	Span(unsigned n);
	Span(const Span& other);
	Span&	operator=(const Span& other);
	~Span();

	// methods
	void		addNumber(int n);
	unsigned	shortestSpan() const;
	unsigned	longestSpan() const;

	void	addNumbers(int start, unsigned n, int span);
	void	print_vector_int() const;
};

#endif /* SPAN_HPP */

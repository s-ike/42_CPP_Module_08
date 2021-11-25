/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 10:57:26 by sikeda            #+#    #+#             */
/*   Updated: 2021/11/25 10:57:27 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "span.hpp"

#define COLOR_RESET	"\033[m"
#define COLOR_RED	"\033[31m"
#define COLOR_CYAN	"\033[36m"

#define CATCH_ERR (std::cout << COLOR_RED << e.what() << COLOR_RESET << std::endl)

void	print_header(const std::string &str)
{
	std::cout
		<< COLOR_CYAN << "\n[ " << str << " ]" << COLOR_RESET
		<< std::endl;
}

int	main()
{
	print_header("subject test");
	try
	{
		Span	sp = Span(5);

		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		sp.print_vector_int();

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		CATCH_ERR;
	}

	print_header("annNumber error");
	try
	{
		Span	sp = Span(5);

		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.addNumber(11);

		sp.print_vector_int();

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		CATCH_ERR;
	}

	print_header("shortestSpan error 1");
	try
	{
		Span	sp = Span(5);

		sp.print_vector_int();

		std::cout << sp.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		CATCH_ERR;
	}

	print_header("shortestSpan error 2");
	try
	{
		Span	sp = Span(5);

		sp.addNumber(5);

		sp.print_vector_int();

		std::cout << sp.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		CATCH_ERR;
	}

	print_header("longestSpan error 1");
	try
	{
		Span	sp = Span(5);

		sp.print_vector_int();

		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		CATCH_ERR;
	}

	print_header("longestSpan error 2");
	try
	{
		Span	sp = Span(5);

		sp.addNumber(5);

		sp.print_vector_int();

		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		CATCH_ERR;
	}

	print_header("normal test");
	try
	{
		Span	sp = Span(5);

		sp.addNumber(100);
		sp.addNumber(-100);
		sp.addNumber(-200);
		sp.addNumber(200);
		sp.addNumber(-200);

		sp.print_vector_int();

		std::cout << "shortestSpan(): " << sp.shortestSpan() << std::endl;
		std::cout << "longestSpan():  " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		CATCH_ERR;
	}

	print_header("big test");
	try
	{
		const unsigned	max = 10000;
		Span			sp = Span(max);

		sp.addNumbers(-100, max, 10);

		sp.print_vector_int();

		std::cout << "shortestSpan(): " << sp.shortestSpan() << std::endl;
		std::cout << "longestSpan():  " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		CATCH_ERR;
	}
}

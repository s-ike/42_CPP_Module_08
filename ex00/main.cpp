/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 02:09:40 by sikeda            #+#    #+#             */
/*   Updated: 2021/11/23 12:52:07 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include "easyfind.hpp"

#define COLOR_RESET	"\033[m"
#define COLOR_RED	"\033[31m"
#define COLOR_CYAN	"\033[36m"

#define CATCH_ERR (std::cout << COLOR_RED << e.what() << COLOR_RESET << std::endl)

void	print_header(const std::string &str)
{
	std::cout << COLOR_CYAN "\n[ " << str << " ]" COLOR_RESET << std::endl;
}

int	main(void)
{
	{
		print_header("vector test");
		try
		{
			std::vector<int> c(5);
			int value = 0;

			for (std::vector<int>::iterator p = c.begin(); p != c.end(); ++p)
				*p = ++value;
			for (std::vector<int>::const_iterator p = c.begin(); p != c.end(); ++p)
				std::cout << *p << ' ';
			std::cout << '\n';

			std::cout << *(easyfind(c, 4)) << '\n';
			std::cout << *(easyfind(c, 5)) << '\n';
			std::cout << *(easyfind(c, 6)) << '\n';
		}
		catch(const std::exception& e)
		{
			CATCH_ERR;
		}
	}
	{
		print_header("list test");
		try
		{
			std::list<int> c(5);
			int value = 0;

			for (std::list<int>::iterator p = c.begin(); p != c.end(); ++p)
				*p = ++value;
			for (std::list<int>::const_iterator p = c.begin(); p != c.end(); ++p)
				std::cout << *p << ' ';
			std::cout << '\n';

			std::cout << *(easyfind(c, 4)) << '\n';
			std::cout << *(easyfind(c, 5)) << '\n';
			std::cout << *(easyfind(c, 6)) << '\n';
		}
		catch(const std::exception& e)
		{
			CATCH_ERR;
		}
	}
	{
		print_header("deque test");
		try
		{
			std::deque<int> c(5);
			int value = 0;

			for (std::deque<int>::iterator p = c.begin(); p != c.end(); ++p)
				*p = ++value;
			for (std::deque<int>::const_iterator p = c.begin(); p != c.end(); ++p)
				std::cout << *p << ' ';
			std::cout << '\n';

			std::cout << *(easyfind(c, 4)) << '\n';
			std::cout << *(easyfind(c, 5)) << '\n';
			std::cout << *(easyfind(c, 6)) << '\n';
		}
		catch(const std::exception& e)
		{
			CATCH_ERR;
		}
	}
	{
		print_header("set test");
		try
		{
			const int a[] = {1, 2, 3, 4, 5};
			std::set<int> c(a, a + 5);

			for (std::set<int>::const_iterator p = c.begin(); p != c.end(); ++p)
				std::cout << *p << ' ';
			std::cout << '\n';

			std::cout << *(easyfind(c, 4)) << '\n';
			std::cout << *(easyfind(c, 5)) << '\n';
			std::cout << *(easyfind(c, 6)) << '\n';
		}
		catch(const std::exception& e)
		{
			CATCH_ERR;
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 01:18:38 by sikeda            #+#    #+#             */
/*   Updated: 2021/11/26 01:18:39 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include "mutantstack.hpp"

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

void	leaks()
{
	print_header("leaks Report");
	if (system("leaks -q a.out"))
		std::cout << COLOR_RED << "LEAK!" << COLOR_RESET << std::endl;
}

int	main()
{
	{
		MutantStack<int> mstack;


		print_header("empty-1");

		std::cout << std::boolalpha << mstack.empty() << std::endl;


		print_header("push & top");

		// {5}
		mstack.push(5);
		// {5, 17}
		mstack.push(17);

		std::cout << mstack.top() << std::endl;


		print_header("empty-2");

		std::cout << std::boolalpha << mstack.empty() << std::endl;


		print_header("pop & size");

		// {5}
		mstack.pop();

		std::cout << mstack.size() << std::endl;

		// {5, 3}
		mstack.push(3);
		// {5, 3, 5}
		mstack.push(5);
		// {5, 3, 5, 737}
		mstack.push(737);
		//[...]
		// {5, 3, 5, 737, 0}
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;


		print_header("iterator");

		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}


		print_header("copy constructor");

		std::stack<int> s(mstack);
		std::cout << s.top() << std::endl;
		s.pop();
		std::cout << s.top() << std::endl;


		print_header("copy constructor-2 & const iterator");

		const MutantStack<int> ms2(mstack);
		for (MutantStack<int>::const_iterator p = ms2.begin(); p < ms2.end(); ++p)
			std::cout << *p << std::endl;


		print_header("assignment operator-1");

		std::stack<int> s2;
		s2 = mstack;
		std::cout << s2.top() << std::endl;
		s2.pop();
		std::cout << s2.top() << std::endl;


		print_header("assignment operator-2 & reverse iterator");

		MutantStack<int> ms3;
		ms3 = mstack;

		for (MutantStack<int>::reverse_iterator p = ms3.rbegin(); p != ms3.rend(); ++p)
			std::cout << *p << std::endl;
	}

	// segmentation fault
	{
		// MutantStack<int> mstack;

		// print_header("MutantStack empty pop");

		// mstack.pop();
	}
	// segmentation fault
	{
		// std::stack<int> stack;

		// print_header("Stack empty pop");

		// stack.pop();
	}

	leaks();
	return 0;
}

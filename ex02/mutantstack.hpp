/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 01:18:35 by sikeda            #+#    #+#             */
/*   Updated: 2021/11/26 23:31:50 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <iostream>

template<class T>
class MutantStack : public std::stack<T>
{
public:
	// orthodox canonical form
	MutantStack()
		: std::stack<T>()
	{
#ifdef DEBUG
		std::cout << "MutantStack default constructor" << std::endl;
#endif
	}
	MutantStack(const MutantStack& other)
		: std::stack<T>(other)
	{
#ifdef DEBUG
		std::cout << "MutantStack copy constructor" << std::endl;
#endif
	}
	MutantStack& operator=(const MutantStack& other)
	{
#ifdef DEBUG
		std::cout << "MutantStack assginment operator" << std::endl;
#endif
		if (this != &other)
			std::stack<T>::operator=(other);
		return *this;
	}
	~MutantStack()
	{
#ifdef DEBUG
		std::cout << "MutantStack destructor" << std::endl;
#endif
	}

	// iterator
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

	iterator begin()
	{
		return this->c.begin();
	}
	iterator end()
	{
		return this->c.end();
	}

	const_iterator begin() const
	{
		return this->c.begin();
	}
	const_iterator end() const
	{
		return this->c.end();
	}

	reverse_iterator rbegin()
	{
		return this->c.rbegin();
	}
	reverse_iterator rend()
	{
		return this->c.rend();
	}

	const_reverse_iterator rbegin() const
	{
		return this->c.rbegin();
	}
	const_reverse_iterator rend() const
	{
		return this->c.rend();
	}
};

#endif /* MUTANTSTACK_HPP */

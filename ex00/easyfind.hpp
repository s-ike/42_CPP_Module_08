/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:24:39 by sikeda            #+#    #+#             */
/*   Updated: 2021/11/23 01:43:32 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>

template <class T>
typename T::iterator	easyfind(T& container, int find)
{
	typename T::iterator it = std::find(container.begin(), container.end(), find);
	if (it == container.end())
		throw std::runtime_error("not found");
	return it;
}

#endif /* EASYFIND_HPP */

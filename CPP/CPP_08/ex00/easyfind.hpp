/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:26:12 by lrondia           #+#    #+#             */
/*   Updated: 2023/01/18 12:32:29 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <iterator>
# include <list>
# include <vector>
# include <stdexcept>

template <typename T>
typename T::iterator	easyfind(T haystack, int needle)	{
	typename T::iterator it;
	
	it = std::find(haystack.begin(), haystack.end(), needle);
	if (it == haystack.end())
		throw std::out_of_range("number out of range");
	return it;
}

#endif
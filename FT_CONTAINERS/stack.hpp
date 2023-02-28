/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:31:00 by lrondia           #+#    #+#             */
/*   Updated: 2023/02/28 18:14:34 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "vector.hpp"
#include "Allouloucator.hpp"

namespace ft {

template < class T, class Container = vector<T> >
class stack
{
	public:
		typedef typename Container::value_type	value_type;
		typedef typename Container::size_type	size_type;
		typedef Container						container_type;

		explicit	stack(const Container &c = container_type()) : c(c) {}
		
		bool		empty() const { return c.empty(); }
		size_type	size() const { return c.size(); }
		value_type	&top() { return c.back(); }
		const value_type	&top() const { return c.back(); }
		void		push(const value_type &x) { c.push_back(x); }
		void		pop() { c.pop_back(); }
		
		bool	operator==(const stack &x) const {
			return c == x.c;
		}

		bool	operator!=(const stack &x) const {
			return c != x.c;
		}

		bool	operator<(const stack &x) const {
			return c < x.c;
		}

		bool	operator>(const stack &x) const {
			return c > x.c;
		}

		bool	operator<=(const stack &x) const {
			return c <= x.c;
		}

		bool	operator>=(const stack &x) const {
			return c >= x.c;
		}

	protected:	
		Container c;
};


}
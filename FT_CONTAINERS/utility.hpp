/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:11:39 by lrondia           #+#    #+#             */
/*   Updated: 2023/03/01 15:47:18 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft {

	template <typename T>
	void	swap(T &a, T &b) {
		T	tmp = a;

		a = b;
		b = tmp;
	}
	
	template <class InputIterator1, class InputIterator2>
	bool equal ( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 )
	{
		for ( ; first1 != last1; first1++, first2++ ) {
			if (!(*first1 == *first2))
				return false;
		}
		return true;
	}

	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
									InputIterator2 first2, InputIterator2 last2)
	{
		for ( ; first1 != last1; first1++, first2++ ) {
			if (first2 == last2 || *first2 < *first1)
				return false;
			else if (*first1 < *first2)
				return true;
		}
		return (first2 != last2);
	}
	
	template <class T1, class T2>
	struct pair {
		
		public:
			typedef T1	first_type;	
			typedef T2	second_type;
		
			first_type	first;
			second_type	second;
			bool		is_empty;

			pair() : first(first_type()), second(second_type()), is_empty(true) {}
			pair(const first_type &x, const second_type &y) : first(x), second(y), is_empty(false) {}
			template <class U, class V>
			pair(const pair <U, V> &x) : first(x.first), second(x.second), is_empty(false) {}

			bool	operator!() { return is_empty; }

			pair<T1, T2>	&operator=(const pair<T1, T2> &other) {
				first = other.first;
				second = other.second;
				is_empty = other.is_empty;
				return *this;
			}
	};

	template <class T1, class T2>
	bool operator==(const pair<T1, T2> &x, const pair<T1, T2> &y) {
		return x.first == y.first && x.second == y.second;
	}

	template <class T1, class T2>
	bool operator!=(const pair<T1, T2> &x, const pair<T1, T2> &y) {
		return !(x == y);
	}

	template <class T1, class T2>
	bool operator<(const pair<T1, T2> &x, const pair<T1, T2> &y) {
		return x.first < y.first || (!(x.first < y.first) && x.second < y.second);
	}

	template <class T1, class T2>
	bool operator>(const pair<T1, T2> &x, const pair<T1, T2> &y) {
		return (y < x);
	}

	template <class T1, class T2>
	bool operator>=(const pair<T1, T2> &x, const pair<T1, T2> &y) {
		return !(x < y);
	}

	template <class T1, class T2>
	bool operator<=(const pair<T1, T2> &x, const pair<T1, T2> &y) {
		return !(y < x);
	}

	template <class T1, class T2>
	pair<T1, T2>	make_pair(const T1 &x, const T2 &y) {
		return pair<T1, T2>(x, y);
	}

	template <class T1, class T2>
	std::ostream	&operator<<(std::ostream &o, const pair<T1, T2> &rhs)	{
		o << "pair first :	" << rhs.first << std::endl;
		o << "pair second :	" << rhs.second << std::endl;
		return o;
	}
}


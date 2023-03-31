/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 23:00:48 by lrondia           #+#    #+#             */
/*   Updated: 2023/03/31 19:26:41 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// #include "Iterator.hpp"
#include "iterator_traits.hpp"

namespace ft {

	template <class Iterator>
	class reverse_iterator :
		public std::iterator<	typename ft::iterator_traits<Iterator>::iterator_category,
								typename ft::iterator_traits<Iterator>::value_type,
								typename ft::iterator_traits<Iterator>::difference_type,
								typename ft::iterator_traits<Iterator>::pointer,
								typename ft::iterator_traits<Iterator>::reference>

	{
		protected:
			Iterator _current;
		
		public:

			typedef Iterator													iterator_type;
			typedef typename ft::iterator_traits<Iterator>::difference_type		difference_type;
			typedef typename ft::iterator_traits<Iterator>::pointer				pointer;
			typedef typename ft::iterator_traits<Iterator>::reference			reference;


			reverse_iterator() {}
			explicit reverse_iterator(Iterator x) : _current(x) {}
			template <class U>
			reverse_iterator(const reverse_iterator<U> &u) : _current(u.base()) {}
			
			template <class U>
			reverse_iterator &operator=(const reverse_iterator<U> &other) {
				_current = other.base();
				return *this;
			}

			Iterator	base() const { return _current; } //explicit
			
			reference	operator*() const {
				Iterator tmp = _current;
				return *--tmp;
			}
			
			pointer		operator->() const { return &(operator *()); }

			reverse_iterator	&operator++() {
				--_current;
				return *this;
			}

			reverse_iterator	operator++(int) {
				reverse_iterator tmp = *this;
				--_current;
				return tmp;
			}
			
			reverse_iterator	&operator--() {
				++_current;
				return *this;
			}
			
			reverse_iterator	operator--(int) {
				reverse_iterator tmp = *this;
				++_current;
				return tmp;
			}

			reverse_iterator	operator+(difference_type n) const { return reverse_iterator(_current - n); }
			
			reverse_iterator	&operator+=(difference_type n) {
				_current -= n;
				return *this;
			}
			
			reverse_iterator	operator-(difference_type n) const { return reverse_iterator(_current + n); }
			
			reverse_iterator	&operator-=(difference_type n) {
				_current += n;
				return *this;
			}
			
			reference			operator[](difference_type n) const { return _current[ - n - 1 ]; }

	};

	template <class I1, class I2>
	bool	operator==(const reverse_iterator<I1> &x, const reverse_iterator<I2> &y) {
		return x.base() == y.base();
	}

	template <class I1, class I2>
	bool	operator!=(const reverse_iterator<I1> &x, const reverse_iterator<I2> &y) {
		return x.base() != y.base();
	}

	template <class I1, class I2>
	bool	operator<(const reverse_iterator<I1> &x, const reverse_iterator<I2> &y) {
		return x.base() > y.base();
	}

	template <class I1, class I2>
	bool	operator>(const reverse_iterator<I1> &x, const reverse_iterator<I2> &y) {
		return x.base() < y.base();
	}

	template <class I1, class I2>
	bool	operator<=(const reverse_iterator<I1> &x, const reverse_iterator<I2> &y) {
		return x.base() >= y.base();
	}

	template <class I1, class I2>
	bool	operator>=(const reverse_iterator<I1> &x, const reverse_iterator<I2> &y) {
		return x.base() <= y.base();
	}

	template <class I1, class I2>
	typename reverse_iterator<I1>::difference_type	operator-(
			const reverse_iterator<I1> &x,
			const reverse_iterator<I2> &y) {
		return y.base() - x.base();
	}

	template <class U>
	reverse_iterator<U>	operator+(typename reverse_iterator<U>::difference_type n, const reverse_iterator<U> &x) {
		return reverse_iterator<U>(x.base() - n);
	}

}

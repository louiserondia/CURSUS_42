/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 23:00:48 by lrondia           #+#    #+#             */
/*   Updated: 2023/02/24 14:10:01 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Iterator.hpp"
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
			Iterator current;
		
		public:

			typedef Iterator													iterator_type;
			typedef typename ft::iterator_traits<Iterator>::difference_type		difference_type;
			typedef typename ft::iterator_traits<Iterator>::pointer				pointer;
			typedef typename ft::iterator_traits<Iterator>::reference			reference;


			reverse_iterator() {}
			explicit reverse_iterator(Iterator x) : current(x) {}
			template <class U>
			reverse_iterator(const reverse_iterator<U> &u) : current(u.current) {}
			
			template <class U>
			reverse_iterator &operator=(const reverse_iterator<U> &other) {
				current = other.current;
				return *this;
			}

			Iterator	base() const { return current; } //explicit
			
			reference	operator*() const {
				Iterator tmp = current;
				return *--tmp;
			}
			
			pointer		operator->() const { return &(operator *()); }

			reverse_iterator	&operator++() {
				--current;
				return *this;
			}

			reverse_iterator	operator++(int n) {
				reverse_iterator tmp = *this;
				--current;
				return tmp;
			}
			
			reverse_iterator	&operator--() {
				++current;
				return *this;
			}
			
			reverse_iterator	operator--(int n) {
				reverse_iterator tmp = *this;
				++current;
				return tmp;
			}

			reverse_iterator	operator+(difference_type n) const { return reverse_iterator(current - n); }
			
			reverse_iterator	&operator+=(difference_type n) {
				current -= n;
				return *this;
			}
			
			reverse_iterator	operator-(difference_type n) const { return reverse_iterator(current + n); }
			
			reverse_iterator	&operator-=(difference_type n) {
				current += n;
				return *this;
			}
			
			reference			operator[](difference_type n) const { return current[ - n - 1 ]; }

	};

	template <class Iterator>
	bool	operator==(const reverse_iterator<Iterator> &x, const reverse_iterator<Iterator> &y) {
		return x.base() == y.base();
	}

	template <class Iterator>
	bool	operator!=(const reverse_iterator<Iterator> &x, const reverse_iterator<Iterator> &y) {
		return x.base() != y.base();
	}

	template <class Iterator>
	bool	operator<(const reverse_iterator<Iterator> &x, const reverse_iterator<Iterator> &y) {
		return x.base() > y.base();
	}

	template <class Iterator>
	bool	operator>(const reverse_iterator<Iterator> &x, const reverse_iterator<Iterator> &y) {
		return x.base() < y.base();
	}

	template <class Iterator>
	bool	operator<=(const reverse_iterator<Iterator> &x, const reverse_iterator<Iterator> &y) {
		return x.base() >= y.base();
	}

	template <class Iterator>
	bool	operator>=(const reverse_iterator<Iterator> &x, const reverse_iterator<Iterator> &y) {
		return x.base() <= y.base();
	}

	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type	operator-(
			const reverse_iterator<Iterator> &x,
			const reverse_iterator<Iterator> &y) {
		return x.base() - y.base();
	}

	template <class Iterator>
	bool	operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator> &x) {
		return reverse_iterator<Iterator>(x.current - n);
	}

}
